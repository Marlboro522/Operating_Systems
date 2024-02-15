#include<linux/kernel.h>
#include<linux/sched.h>
#include<linux/module.h>
MODULE_LICENSE("GPL");
int pid=21364;
module_param(pid,int,0);
int print_other(void){
	struct task_struct *task;
	task = pid_task(find_vpid(pid), PIDTYPE_PID);
	if (task == NULL) {
		printk(KERN_INFO "Process with pid not found");
		return 1;
	}
	printk(KERN_INFO "Process Details:\n (PID %d):\n", pid);
	printk(KERN_INFO "Name: %s\n", task->comm);
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
	while (task->parent != task) {
	        task = task->parent;
	        printk(KERN_INFO "Parent Process Information:\n");
	        printk(KERN_INFO "Name: %s\n", task->comm);
	        printk(KERN_INFO "PID: %d\n", task->pid);
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
	    }
	
	    return 0;
}
void print_other_c(void) {
    printk(KERN_INFO "Exiting print_other module\n");
}
module_init(print_other);
module_exit(print_other_c);
