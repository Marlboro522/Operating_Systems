#include<linux/kernel.h>
#include<linux/sched.h>
#include<linux/module.h>
MODULE_LICENSE("GPL");
int print_self(void){ //init module
	struct task_struct *task=current;
	//current is a macro in the kernnel.h file
	//it returns a pointer to the task_struct instance 
	printk(KERN_INFO "Current Process Details: \n");
	printk(KERN_INFO "NAme: %s\n",task->comm);
	printk(KERN_INFO "Process_ID: %d\n",task->pid);
	switch (task->state) {
	        case TASK_RUNNING:
	            printk(KERN_INFO "Process State: TASK_RUNNING\n");
	            break;
	        case TASK_INTERRUPTIBLE:
	            printk(KERN_INFO "Process State: TASK_INTERRUPTIBLE\n");
	            break;
	        case TASK_UNINTERRUPTIBLE:
	            printk(KERN_INFO "Process State: TASK_UNINTERRUPTIBLE\n");
	            break;
	        case TASK_STOPPED:
	            printk(KERN_INFO "Process State: TASK_STOPPED\n");
	            break;
	        case TASK_TRACED:
	            printk(KERN_INFO "Process State: TASK_TRACED\n");
	            break;
	        case EXIT_ZOMBIE:
	            printk(KERN_INFO "Process State: EXIT_ZOMBIE\n");
	            break;
	        default:
	            printk(KERN_INFO "Process State: Unknown\n");
	            break;
	    };
	while(task->parent != task){
		task=task->parent;
		printk(KERN_INFO "Name; %s\n",task->comm);
		printk(KERN_INFO "Process_ID: %d\n",task->pid);
		switch (task->state) {
		        case TASK_RUNNING:
		            printk(KERN_INFO "Process State: TASK_RUNNING\n");
		            break;
		        case TASK_INTERRUPTIBLE:
		            printk(KERN_INFO "Process State: TASK_INTERRUPTIBLE\n");
		            break;
		        case TASK_UNINTERRUPTIBLE:
		            printk(KERN_INFO "Process State: TASK_UNINTERRUPTIBLE\n");
		            break;
		        case TASK_STOPPED:
		            printk(KERN_INFO "Process State: TASK_STOPPED\n");
		            break;
		        case TASK_TRACED:
		            printk(KERN_INFO "Process State: TASK_TRACED\n");
		            break;
		        case EXIT_ZOMBIE:
		            printk(KERN_INFO "Process State: EXIT_ZOMBIE\n");
		            break;
		        default:
		            printk(KERN_INFO "Process State: Unknown\n");
		            break;
		    };
		printk(KERN_INFO "\n");
	} //This loop runs until init since task wil go up the heirarchy until init
	//and init is the parent of init and the looop breaks;
	return 0;
	}
void print_self_c(void){
		printk(KERN_INFO "Program served it's purpose, Goodbye world");
}
//invocation into the kernel
module_init(print_self);
module_exit(print_self_c);
