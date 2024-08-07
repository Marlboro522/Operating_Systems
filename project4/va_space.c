#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>

int pid = 0;
module_param(pid, int, 0);

static int va_space_mod(void) {

    printk(KERN_INFO "print_virtual_address_space_module\n");

    struct task_struct *task = pid_task(find_vpid(pid), PIDTYPE_PID);
    struct mm_struct *mm;
    struct vm_area_struct *vma;

    if (!task) {
        printk(KERN_ERR "No task found for PID %d\n", pid);
        return -ESRCH;
    }

    mm = task->mm;

    if (!mm) {
        printk(KERN_ERR "No memory map found for PID %d\n", pid);
        return -EFAULT;
    }

    unsigned long int total_mem = 0; 

    for (vma = mm->mmap; vma; vma = vma->vm_next) {
        total_mem += vma->vm_end - vma->vm_start;
    }

    printk(KERN_INFO "Total virtual memory size of [%d]: %ld in Bytes", pid, total_mem);

    return 0;

}

static void cleanup_mod(void)
{
    printk(KERN_INFO "Removing print_virtual_address_space_module\n");
}

module_init(va_space_mod);
module_exit(cleanup_mod);

MODULE_LICENSE("GPL");