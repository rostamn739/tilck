
#include <exos/common/basic_defs.h>
#include <exos/common/string_util.h>
#include <exos/common/utils.h>

#include <exos/kernel/tasklet.h>
#include <exos/kernel/process.h>
#include <exos/kernel/debug_utils.h>

static volatile int counter = 0;
static u32 cycles_begin;

static void test_tasklet_func()
{
   counter++;
}

static void end_test()
{
   const int max_tasklets = get_tasklet_runner_limit(0);
   const int tot_iters = max_tasklets * 10;

   u64 elapsed = RDTSC() - cycles_begin;
   VERIFY(counter == tot_iters);
   printk("[selftest_tasklet] END\n");
   printk("[selftest_tasklet] Avg cycles per tasklet "
          "(enqueue + execute): %llu\n", elapsed/counter);
   debug_qemu_turn_off_machine();
}

void selftest_tasklet(void)
{
   const int max_tasklets = get_tasklet_runner_limit(0);
   const int tot_iters = max_tasklets * 10;

   bool added;
   counter = 0;

   ASSERT(is_preemption_enabled());
   printk("[selftest_tasklet] BEGIN\n");

   cycles_begin = RDTSC();

   for (int i = 0; i < tot_iters; i++) {

      do {
         added = enqueue_tasklet0(0, &test_tasklet_func);
      } while (!added);

   }

   do {
      added = enqueue_tasklet0(0, &end_test);
   } while (!added);
}

void selftest_tasklet_perf(void)
{
   bool added;
   int n = 0;

   u64 start, elapsed;

   start = RDTSC();

   while (true) {

      added = enqueue_tasklet0(0, &test_tasklet_func);

      if (!added)
         break;

      n++;
   }

   elapsed = RDTSC() - start;
   printk("Avg. tasklet enqueue cycles: %llu [%i tasklets]\n", elapsed/n, n);
   debug_qemu_turn_off_machine();
}
