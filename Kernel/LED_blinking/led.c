#include <linux/module.h>
#include <linux/configfs.h>
#include <linux/init.h>
#include <linux/tty.h>          /* For tty_struct */
#include <linux/kd.h>           /* For KDSETLED */
#include <linux/vt_kern.h>      /* For fg_console */
#include <linux/console_struct.h> /* For vc_cons */

MODULE_DESCRIPTION("Blink the Caps Lock LED");
MODULE_LICENSE("GPL");

static struct timer_list my_timer;
static int led_state = 0;

// The Heartbeat function
static void timer_callback(struct timer_list *t) {

    // This is a "old school" but reliable way to talk to console LEDs
    // It targets the current foreground console

    struct tty_driver *my_driver;
    my_driver = vc_cons[fg_console].d->port.tty->driver;

    if (led_state == 0) {
        led_state = 0x04; // Hex code for Caps Lock LED
    } else {
        led_state = 0;    // Turn all off
    }

    // Send the command to the hardware driver
    (my_driver->ops->ioctl)(vc_cons[fg_console].d->port.tty, KDSETLED, led_state);

    // Schedule next blink in 500ms
    mod_timer(&my_timer, jiffies + msecs_to_jiffies(80));
}

static int __init led_init(void) {
    printk(KERN_INFO "LED: Module loaded. Look at your keyboard!\n");
    
    timer_setup(&my_timer, timer_callback, 0);
    mod_timer(&my_timer, jiffies + msecs_to_jiffies(500));
    
    return 0;
}

static void __exit led_exit(void) {
    timer_shutdown(&my_timer);
    
    // Reset LED to normal state (0xFF tells the kernel to return control to the OS)
    struct tty_driver *my_driver;
    my_driver = vc_cons[fg_console].d->port.tty->driver;
    (my_driver->ops->ioctl)(vc_cons[fg_console].d->port.tty, KDSETLED, 0xFF);
    
    printk(KERN_INFO "LED: Module unloaded.\n");
}

module_init(led_init);
module_exit(led_exit);
