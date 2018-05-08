
#include <common/basic_defs.h>
#include <common/string_util.h>
#include <common/arch/generic_x86/vga_textmode_defs.h>

#include <exos/term.h>
#include <exos/process.h>
#include <exos/interrupts.h>

#define PRINTK_COLOR COLOR_GREEN
#define PRINTK_RINGBUF_FLUSH_COLOR COLOR_BLUE
#define PRINTK_NOSPACE_IN_RBUF_FLUSH_COLOR COLOR_MAGENTA
#define PRINTK_PANIC_COLOR COLOR_GREEN

static bool
write_in_buf_str(char **buf_ref, char *buf_end, const char *s)
{
   char *ptr = *buf_ref;

   while (*s && ptr < buf_end) {
      *ptr++ = *s++;
   }

   *buf_ref = ptr;
   return ptr < buf_end;
}

static inline bool
write_in_buf_char(char **buf_ref, char *buf_end, char c)
{
   char *ptr = *buf_ref;
   *ptr++ = c;
   *buf_ref = ptr;
   return ptr < buf_end;
}

#define WRITE_STR(s)                                 \
   do {                                              \
      if (!write_in_buf_str(&buf, buf_end, (s)))     \
         goto out;                                   \
   } while (0)

#define WRITE_CHAR(c)                                \
   do {                                              \
      if (!write_in_buf_char(&buf, buf_end, (c)))    \
         goto out;                                   \
   } while (0)


int vsnprintk(char *buf, size_t size, const char *fmt, va_list args)
{
   char *const initial_buf = buf;
   char *buf_end = buf + size;
   char intbuf[32];

   while (*fmt) {

      if (*fmt != '%') {
         WRITE_CHAR(*fmt++);
         continue;
      }

      // *fmt is '%'
      ++fmt;

      if (*fmt == '%')
         continue;

      switch (*fmt) {

      case 'l':

         if (!*++fmt)
            goto out;

         if (*fmt == 'l') {

            if (!*++fmt)
               goto out;

            if (*fmt == 'u') {
               uitoa64_dec(va_arg(args, u64), intbuf);
               WRITE_STR(intbuf);
            } else if (*fmt == 'i' || *fmt == 'd') {
               itoa64(va_arg(args, s64), intbuf);
               WRITE_STR(intbuf);
            }

         }
         break;

      case 'd':
      case 'i':
         itoa32(va_arg(args, s32), intbuf);
         WRITE_STR(intbuf);
         break;

      case 'u':
         uitoa32_dec(va_arg(args, u32), intbuf);
         WRITE_STR(intbuf);
         break;

      case 'x':
         uitoa32_hex(va_arg(args, u32), intbuf);
         WRITE_STR(intbuf);
         break;

      case 'c':
         term_write_char(va_arg(args, s32));
         break;

      case 's':
         WRITE_STR(va_arg(args, const char *));
         break;

      case 'p':
         uitoa32_hex_fixed(va_arg(args, uptr), intbuf);
         WRITE_STR("0x");
         WRITE_STR(intbuf);
         break;

      default:
         WRITE_CHAR('%');
         WRITE_CHAR(*fmt);
      }

      ++fmt;
   }

out:
   buf[ buf < buf_end ? 0 : -1 ] = 0;
   return (buf - initial_buf);
}

int snprintk(char *buf, size_t size, const char *fmt, ...)
{
   int written;

   va_list args;
   va_start(args, fmt);
   written = vsnprintk(buf, size, fmt, args);
   va_end(args);

   return written;
}

typedef struct {

   union {

      struct {
         u32 used : 10;
         u32 read_pos : 10;
         u32 write_pos : 10;
         u32 in_printk : 1;
         u32 unused : 1;
      };

      u32 raw;
   };

} ringbuf_stat;

static char printk_rbuf[1024];
static volatile ringbuf_stat printk_rbuf_stat;

/*
 * NOTE: the ring buf cannot be larger than 1024 elems because the fields
 * 'used', 'read_pos' and 'write_pos' and 10 bits long and we CANNOT extend
 * them in 32 bits. Such approach is convenient because with everything packed
 * in 32 bits, we can do atomic operations.
 */
STATIC_ASSERT(sizeof(printk_rbuf) <= 1024);

static void printk_raw_flush(char *buf, size_t size, u8 color)
{
   for (u32 i = 0; i < size; i++) {
      term_write_char2(buf[i], color);
   }
}

static void printk_flush(char *buf, size_t size)
{
   // First, write to screen the 'buf' buffer.
   printk_raw_flush(buf, size, PRINTK_COLOR);

   // Then, flush the text in the ring buffer (if any).
   ringbuf_stat cs, ns;

   char minibuf[80];
   u32 to_read = 0;

   while (true) {

      do {
         cs = printk_rbuf_stat;
         ns = printk_rbuf_stat;

         /* We at most 'sizeof(minibuf)' bytes at a time */
         to_read = MIN(sizeof(minibuf), ns.used);

         /* And copy them to our minibuf */
         for (u32 i = 0; i < to_read; i++)
            minibuf[i] = printk_rbuf[(cs.read_pos + i) % sizeof(printk_rbuf)];

         /* Increase read_pos and decrease used */
         ns.read_pos = (ns.read_pos + to_read) % sizeof(printk_rbuf);
         ns.used -= to_read;

         if (!to_read)
            ns.in_printk = 0;

         /* Repeat that until we were able to do that atomically */

      } while (!BOOL_COMPARE_AND_SWAP(&printk_rbuf_stat.raw, cs.raw, ns.raw));

      /* Note: we check that in_printk in cs (current state) is unset! */
      if (!cs.in_printk)
         break;

      printk_raw_flush(minibuf, to_read, PRINTK_RINGBUF_FLUSH_COLOR);
   }
}

static void printk_append_to_ringbuf(char *buf, size_t size)
{
   ringbuf_stat cs, ns;

   do {
      cs = printk_rbuf_stat;
      ns = printk_rbuf_stat;

      if (cs.used + size > sizeof(printk_rbuf)) {
         printk_raw_flush(buf, size, PRINTK_NOSPACE_IN_RBUF_FLUSH_COLOR);
         return;
      }

      ns.used += size;
      ns.write_pos = (ns.write_pos + size) % sizeof(printk_rbuf);

   } while (!BOOL_COMPARE_AND_SWAP(&printk_rbuf_stat.raw, cs.raw, ns.raw));

   // Now we have some allocated space in the ringbuf

   for (u32 i = 0; i < size; i++)
      printk_rbuf[(cs.write_pos + i) % sizeof(printk_rbuf)] = buf[i];
}

void vprintk(const char *fmt, va_list args)
{
   char buf[256];
   int written = 0;

   if (!in_panic())
      written = snprintk(buf, sizeof(buf), "[kernel] ");

   written += vsnprintk(buf + written, sizeof(buf) - written, fmt, args);

   if (in_panic()) {
      printk_raw_flush(buf, written, PRINTK_PANIC_COLOR);
      return;
   }

   disable_preemption();
   {
      ringbuf_stat cs, ns;

      do {
         cs = printk_rbuf_stat;
         ns = printk_rbuf_stat;
         ns.in_printk = 1;
      } while (!BOOL_COMPARE_AND_SWAP(&printk_rbuf_stat.raw, cs.raw, ns.raw));

      if (!cs.in_printk) {

         /*
          * in_printk was 0 and we set it to 1.
          * printk_flush() will restore it to 0.
          */
         printk_flush(buf, written);

      } else {

         /* in_printk was already 1 */
         printk_append_to_ringbuf(buf, written);
      }

   }
   enable_preemption();
}

void printk(const char *fmt, ...)
{
   va_list args;
   va_start(args, fmt);
   vprintk(fmt, args);
   va_end(args);
}
