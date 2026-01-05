#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

static int __init hello_start(void){
    printk(KERN_INFO "Hello world !\n");
    return 0;
}

static void __exit hello_exit(void){
    printk(KERN_INFO "Goodbye world !\n");
}

module_init(hello_start);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Maracci");
MODULE_DESCRIPTION("A hello world module.");
