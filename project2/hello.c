#include<linux/module.h>
#include<linux/kernel.h>
int init(void){
	printk(KERN_INFO "Hello World!\n");
	return 0;
}
void cleanup(void){
	printk(KERN_INFO "Goodbye World!\n");
}
module_init(init);
module_exit(cleanup);
MODULE_LICENSE("GPL");
