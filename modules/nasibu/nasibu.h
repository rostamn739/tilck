#include <stdbool.h>

#define KB 1024

#define MB 1048576

#define VER_MAJOR 0

#define VER_MINOR 1

#define VER_PATCH 3

#define KERNEL_STACK_PAGES 2

#define KERNEL_PADDR 1048576

#define KERNEL_BASE_VA 3221225472

#define LINEAR_MAPPING_MB 896

#define FAT_TEST_DIR 0

#define DEBUG_CHECKS 1

#define KERNEL_TEST_INT 0

#define IS_RELEASE_BUILD 0

#define LINEAR_MAPPING_SIZE 939524096

#define LINEAR_MAPPING_END 4160749568

#define FREE_MEM_POISON_VAL 4205562622

#define USER_ARGS_PAGE_COUNT 1

#define MAX_TTYS 9

#define MAX_PATH 256

#define MAX_PID 8191

#define _STDINT_H 1

#define _FEATURES_H 1

#define _DEFAULT_SOURCE 1

#define __GLIBC_USE_ISOC2X 0

#define __USE_ISOC11 1

#define __USE_ISOC99 1

#define __USE_ISOC95 1

#define __USE_POSIX_IMPLICITLY 1

#define _POSIX_SOURCE 1

#define _POSIX_C_SOURCE 200809

#define __USE_POSIX 1

#define __USE_POSIX2 1

#define __USE_POSIX199309 1

#define __USE_POSIX199506 1

#define __USE_XOPEN2K 1

#define __USE_XOPEN2K8 1

#define _ATFILE_SOURCE 1

#define __USE_MISC 1

#define __USE_ATFILE 1

#define __USE_FORTIFY_LEVEL 0

#define __GLIBC_USE_DEPRECATED_GETS 0

#define __GLIBC_USE_DEPRECATED_SCANF 0

#define _STDC_PREDEF_H 1

#define __STDC_IEC_559__ 1

#define __STDC_IEC_559_COMPLEX__ 1

#define __STDC_ISO_10646__ 201706

#define __GNU_LIBRARY__ 6

#define __GLIBC__ 2

#define __GLIBC_MINOR__ 33

#define _SYS_CDEFS_H 1

#define __glibc_c99_flexarr_available 1

#define __WORDSIZE 32

#define __WORDSIZE32_SIZE_ULONG 0

#define __WORDSIZE32_PTRDIFF_LONG 0

#define __WORDSIZE_TIME64_COMPAT32 0

#define __LDOUBLE_REDIRECTS_TO_FLOAT128_ABI 0

#define __HAVE_GENERIC_SELECTION 1

#define __GLIBC_USE_LIB_EXT2 0

#define __GLIBC_USE_IEC_60559_BFP_EXT 0

#define __GLIBC_USE_IEC_60559_BFP_EXT_C2X 0

#define __GLIBC_USE_IEC_60559_FUNCS_EXT 0

#define __GLIBC_USE_IEC_60559_FUNCS_EXT_C2X 0

#define __GLIBC_USE_IEC_60559_TYPES_EXT 0

#define _BITS_TYPES_H 1

#define __TIMESIZE 32

#define _BITS_TYPESIZES_H 1

#define __RLIM_T_MATCHES_RLIM64_T 0

#define __STATFS_MATCHES_STATFS64 0

#define __KERNEL_OLD_TIMEVAL_MATCHES_TIMEVAL64 0

#define __FD_SETSIZE 1024

#define _BITS_TIME64_H 1

#define _BITS_WCHAR_H 1

#define _BITS_STDINT_INTN_H 1

#define _BITS_STDINT_UINTN_H 1

#define INT8_MIN -128

#define INT16_MIN -32768

#define INT32_MIN -2147483648

#define INT8_MAX 127

#define INT16_MAX 32767

#define INT32_MAX 2147483647

#define UINT8_MAX 255

#define UINT16_MAX 65535

#define UINT32_MAX 4294967295

#define INT_LEAST8_MIN -128

#define INT_LEAST16_MIN -32768

#define INT_LEAST32_MIN -2147483648

#define INT_LEAST8_MAX 127

#define INT_LEAST16_MAX 32767

#define INT_LEAST32_MAX 2147483647

#define UINT_LEAST8_MAX 255

#define UINT_LEAST16_MAX 65535

#define UINT_LEAST32_MAX 4294967295

#define INT_FAST8_MIN -128

#define INT_FAST16_MIN -2147483648

#define INT_FAST32_MIN -2147483648

#define INT_FAST8_MAX 127

#define INT_FAST16_MAX 2147483647

#define INT_FAST32_MAX 2147483647

#define UINT_FAST8_MAX 255

#define UINT_FAST16_MAX 4294967295

#define UINT_FAST32_MAX 4294967295

#define INTPTR_MIN -2147483648

#define INTPTR_MAX 2147483647

#define UINTPTR_MAX 4294967295

#define PTRDIFF_MIN -2147483648

#define PTRDIFF_MAX 2147483647

#define SIG_ATOMIC_MIN -2147483648

#define SIG_ATOMIC_MAX 2147483647

#define SIZE_MAX 4294967295

#define WINT_MIN 0

#define WINT_MAX 4294967295

#define true_ 1

#define false_ 0

#define __bool_true_false_are_defined 1

#define __alignas_is_defined 1

#define __alignof_is_defined 1

#define _INTTYPES_H 1

#define ____gwchar_t_defined 1

#define _LIBC_LIMITS_H_ 1

#define MB_LEN_MAX 16

#define _BITS_POSIX1_LIM_H 1

#define _POSIX_AIO_LISTIO_MAX 2

#define _POSIX_AIO_MAX 1

#define _POSIX_ARG_MAX 4096

#define _POSIX_CHILD_MAX 25

#define _POSIX_DELAYTIMER_MAX 32

#define _POSIX_HOST_NAME_MAX 255

#define _POSIX_LINK_MAX 8

#define _POSIX_LOGIN_NAME_MAX 9

#define _POSIX_MAX_CANON 255

#define _POSIX_MAX_INPUT 255

#define _POSIX_MQ_OPEN_MAX 8

#define _POSIX_MQ_PRIO_MAX 32

#define _POSIX_NAME_MAX 14

#define _POSIX_NGROUPS_MAX 8

#define _POSIX_OPEN_MAX 20

#define _POSIX_PATH_MAX 256

#define _POSIX_PIPE_BUF 512

#define _POSIX_RE_DUP_MAX 255

#define _POSIX_RTSIG_MAX 8

#define _POSIX_SEM_NSEMS_MAX 256

#define _POSIX_SEM_VALUE_MAX 32767

#define _POSIX_SIGQUEUE_MAX 32

#define _POSIX_SSIZE_MAX 32767

#define _POSIX_STREAM_MAX 8

#define _POSIX_SYMLINK_MAX 255

#define _POSIX_SYMLOOP_MAX 8

#define _POSIX_TIMER_MAX 32

#define _POSIX_TTY_NAME_MAX 9

#define _POSIX_TZNAME_MAX 6

#define _POSIX_CLOCKRES_MIN 20000000

#define NR_OPEN 1024

#define NGROUPS_MAX 65536

#define ARG_MAX 131072

#define LINK_MAX 127

#define MAX_CANON 255

#define MAX_INPUT 255

#define NAME_MAX 255

#define PATH_MAX 4096

#define PIPE_BUF 4096

#define XATTR_NAME_MAX 255

#define XATTR_SIZE_MAX 65536

#define XATTR_LIST_MAX 65536

#define RTSIG_MAX 32

#define _POSIX_THREAD_KEYS_MAX 128

#define PTHREAD_KEYS_MAX 1024

#define _POSIX_THREAD_DESTRUCTOR_ITERATIONS 4

#define PTHREAD_DESTRUCTOR_ITERATIONS 4

#define _POSIX_THREAD_THREADS_MAX 64

#define AIO_PRIO_DELTA_MAX 20

#define PTHREAD_STACK_MIN 16384

#define DELAYTIMER_MAX 2147483647

#define TTY_NAME_MAX 32

#define LOGIN_NAME_MAX 256

#define HOST_NAME_MAX 64

#define MQ_PRIO_MAX 32768

#define SEM_VALUE_MAX 2147483647

#define _BITS_POSIX2_LIM_H 1

#define _POSIX2_BC_BASE_MAX 99

#define _POSIX2_BC_DIM_MAX 2048

#define _POSIX2_BC_SCALE_MAX 99

#define _POSIX2_BC_STRING_MAX 1000

#define _POSIX2_COLL_WEIGHTS_MAX 2

#define _POSIX2_EXPR_NEST_MAX 32

#define _POSIX2_LINE_MAX 2048

#define _POSIX2_RE_DUP_MAX 255

#define _POSIX2_CHARCLASS_NAME_MAX 14

#define BC_BASE_MAX 99

#define BC_DIM_MAX 2048

#define BC_SCALE_MAX 99

#define BC_STRING_MAX 1000

#define COLL_WEIGHTS_MAX 255

#define EXPR_NEST_MAX 32

#define LINE_MAX 2048

#define CHARCLASS_NAME_MAX 2048

#define RE_DUP_MAX 32767

#define __GNUC_VA_LIST 1

#define _SYS_TYPES_H 1

#define __clock_t_defined 1

#define __clockid_t_defined 1

#define __time_t_defined 1

#define __timer_t_defined 1

#define __BIT_TYPES_DEFINED__ 1

#define _ENDIAN_H 1

#define _BITS_ENDIAN_H 1

#define __LITTLE_ENDIAN 1234

#define __BIG_ENDIAN 4321

#define __PDP_ENDIAN 3412

#define _BITS_ENDIANNESS_H 1

#define __BYTE_ORDER 1234

#define __FLOAT_WORD_ORDER 1234

#define LITTLE_ENDIAN 1234

#define BIG_ENDIAN 4321

#define PDP_ENDIAN 3412

#define BYTE_ORDER 1234

#define _BITS_BYTESWAP_H 1

#define _BITS_UINTN_IDENTITY_H 1

#define _SYS_SELECT_H 1

#define __sigset_t_defined 1

#define __timeval_defined 1

#define _STRUCT_TIMESPEC 1

#define FD_SETSIZE 1024

#define _BITS_PTHREADTYPES_COMMON_H 1

#define _THREAD_SHARED_TYPES_H 1

#define _BITS_PTHREADTYPES_ARCH_H 1

#define __SIZEOF_PTHREAD_MUTEX_T 24

#define __SIZEOF_PTHREAD_ATTR_T 36

#define __SIZEOF_PTHREAD_RWLOCK_T 32

#define __SIZEOF_PTHREAD_BARRIER_T 20

#define __SIZEOF_PTHREAD_MUTEXATTR_T 4

#define __SIZEOF_PTHREAD_COND_T 48

#define __SIZEOF_PTHREAD_CONDATTR_T 4

#define __SIZEOF_PTHREAD_RWLOCKATTR_T 8

#define __SIZEOF_PTHREAD_BARRIERATTR_T 4

#define _THREAD_MUTEX_INTERNAL_H 1

#define __PTHREAD_MUTEX_HAVE_PREV 0

#define __have_pthread_attr_t 1

#define NBITS 32

#define KMALLOC_METADATA_BLOCK_NODE_SIZE 1

#define KMALLOC_HEAPS_COUNT 32

#define SMALL_HEAP_MBS 32

#define SMALL_HEAP_SIZE 32768

#define KMALLOC_FL_MULTI_STEP 2147483648

#define KMALLOC_FL_NO_ACTUAL_ALLOC 1073741824

#define KMALLOC_FL_DMA 536870912

#define KMALLOC_FL_RESV_FLAGS_MASK 268435456

#define KMALLOC_FL_DONT_ACCOUNT 134217728

#define KMALLOC_FL_SUB_BLOCK_MIN_SIZE_MASK 134217727

#define KFREE_FL_MULTI_STEP 2147483648

#define KFREE_FL_NO_ACTUAL_FREE 1073741824

#define KFREE_FL_ALLOW_SPLIT 536870912

typedef long long __intmax_t;

typedef __intmax_t intmax_t;

typedef struct imaxdiv_t {
  long long quot;
  long long rem;
} imaxdiv_t;

typedef unsigned long long __uintmax_t;

typedef __uintmax_t uintmax_t;

typedef int __gwchar_t;

typedef long __fd_mask;

typedef struct fd_set {
  __fd_mask __fds_bits[32];
} fd_set;

typedef long __time_t;

typedef long __suseconds_t;

typedef struct timeval {
  __time_t tv_sec;
  __suseconds_t tv_usec;
} timeval;

typedef long __syscall_slong_t;

typedef struct timespec {
  __time_t tv_sec;
  __syscall_slong_t tv_nsec;
} timespec;

typedef struct __sigset_t {
  unsigned long __val[32];
} __sigset_t;

typedef uint32_t u32_;

typedef struct kmalloc_heap {
  uint8_t _unused[0];
} kmalloc_heap;

typedef unsigned long ulong;

typedef bool (*virtual_alloc_and_map_func)(ulong vaddr, size_t page_count);

typedef void (*virtual_free_and_unmap_func)(ulong vaddr, size_t page_count);

typedef struct kmalloc_acc {
  u32_ elem_size;
  u32_ elem_count;
  u32_ curr_elem;
  char *buf;
} kmalloc_acc;

typedef int tristate;

#define tristate_tri_unknown -1

#define tristate_tri_no 0

#define tristate_tri_yes 1

extern intmax_t imaxabs(intmax_t __n);

extern struct imaxdiv_t imaxdiv(intmax_t __numer, intmax_t __denom);

extern intmax_t strtoimax(const char *__nptr, char **__endptr, int __base);

extern uintmax_t strtoumax(const char *__nptr, char **__endptr, int __base);

extern intmax_t wcstoimax(const __gwchar_t *__nptr, __gwchar_t **__endptr, int __base);

extern uintmax_t wcstoumax(const __gwchar_t *__nptr, __gwchar_t **__endptr, int __base);

extern int select(int __nfds,
                  struct fd_set *__readfds,
                  struct fd_set *__writefds,
                  struct fd_set *__exceptfds,
                  struct timeval *__timeout);

extern int pselect(int __nfds,
                   struct fd_set *__readfds,
                   struct fd_set *__writefds,
                   struct fd_set *__exceptfds,
                   const struct timespec *__timeout,
                   const struct __sigset_t *__sigmask);

extern void panic(const char *fmt);

extern void not_reached(const char *file, int line);

extern void not_implemented(const char *file, int line);

extern void assert_failed(const char *expr, const char *file, int line);

extern void early_init_kmalloc(void);

extern void init_kmalloc(void);

extern void *general_kmalloc(size_t *size, u32_ flags);

extern void general_kfree(void *ptr, size_t *size, u32_ flags);

extern bool is_kmalloc_initialized(void);

extern bool kmalloc_create_heap(struct kmalloc_heap *h,
                                ulong vaddr,
                                size_t size,
                                size_t min_block_size,
                                size_t alloc_block_size,
                                bool linear_mapping,
                                void *metadata_nodes,
                                virtual_alloc_and_map_func valloc,
                                virtual_free_and_unmap_func vfree);

extern struct kmalloc_heap *kmalloc_create_regular_heap(ulong vaddr,
                                                        size_t size,
                                                        size_t min_block_size);

extern void kmalloc_destroy_heap(struct kmalloc_heap *h);

extern struct kmalloc_heap *kmalloc_heap_dup(struct kmalloc_heap *h);

extern struct kmalloc_heap *kmalloc_heap_dup_expanded(struct kmalloc_heap *h, size_t sz);

extern void *per_heap_kmalloc(struct kmalloc_heap *h, size_t *size, u32_ flags);

extern void per_heap_kfree(struct kmalloc_heap *h, void *ptr, size_t *size, u32_ flags);

extern void kmalloc_create_accelerator(struct kmalloc_acc *a, u32_ elem_s, u32_ elem_c);

extern void *kmalloc_accelerator_get_elem(struct kmalloc_acc *a);

extern void kmalloc_destroy_accelerator(struct kmalloc_acc *a);

extern void *kzmalloc(size_t size);

extern size_t kmalloc_get_heap_struct_size(void);

extern size_t kmalloc_get_max_tot_heap_free(void);

extern void *aligned_kmalloc(size_t size, u32_ align);

extern void aligned_kfree2(void *ptr, size_t size);

extern void *vmalloc(size_t size);

extern void vfree2(void *ptr, size_t size);
