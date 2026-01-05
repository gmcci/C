#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/timer.h>
#include <linux/jiffies.h>

static struct timer_list my_timer;
static int count = 0;

void timer_callback(struct timer_list *t){
    count++;
    printk(KERN_INFO "Heartbeat: beat number %d \n", count);

     // Timers are "one-shot". To make it loop, we must re-schedule it.
    // msecs_to_jiffies converts milliseconds to kernel clock ticks.

    mod_timer(&my_timer, jiffies + msecs_to_jiffies(5000));
}

static int __init heartbeat_init(void){
    printk(KERN_INFO "HEARTBEAT: Module loaded. Starting timer ...");

    // Initialize the timer
    timer_setup(&my_timer, timer_callback, 0);

    // Start the timer for the first time, 5 seconds from now  
    mod_timer(&my_timer, jiffies + msecs_to_jiffies(5000));

    return 0;
}

static void __exit heartbeat_exit(void){

    // CRITICAL: Always delete the timer before leaving, 
    // or the kernel will try to jump to code that no longer exists (PANIC!)

    printk(KERN_INFO "HEARTBEAT: Module unloaded. Timer stopped. Goodbye.");
    timer_shutdown(&my_timer);
}

module_init(heartbeat_init);
module_exit(heartbeat_exit);
MODULE_LICENSE("GPL");
