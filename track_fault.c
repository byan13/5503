#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kprobes.h>

MODULE_LICENSE("GPL");
static int pid = 0;
module_param(pid, int, S_IRUGO);

#define MAX_SYMBOL_LEN 64
static char symbol[64] = "__handle_mm_fault";
module_param_string(symbol, symbol, sizeof(symbol), 0644);

// Allocate kprobe structure, set target function name
static struct kprobe kp = {
			   .symbol_name = symbol,
};

// Called just before the probed instruction is executed
static int handler_pre(struct kprob *p, struct pt_regs *regs) {
  if(current->pid == pid) {
    printk(KERN_ALERT "Target process faults at %lx.\n", regs->si;)
  }
  return 0;
}

static int __init kprobe_init(void) {
  kp.pre_handler = handler_pre;
  
  if(register_kprob(&kp) < 0) {
    pr_err("register_kprobe failed.\n");
  }
  pr_info("Planted kprobe at %p\n", kp.addr);
  
  return 0;
}

static void__exit kprobe_exit(void) {
  unregister_kprobe(&kp);
  pr_info("kprobe at %p unregistered\n", kp.addr);
}

module_init(kprobe_init)
module_exit(kprobe_exit)


  
