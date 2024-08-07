#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>
#include <linux/mm.h>
#include <linux/highmem.h>
#include <linux/pid.h>

int pid = 0;
char* virtual_address = NULL;
module_param(virtual_address, charp, 0644);
module_param(pid, int, 0);

static int va_status_mod(void) {

    printk(KERN_INFO "va_status_module\n");

    struct task_struct *task = pid_task(find_vpid(pid), PIDTYPE_PID);
    struct mm_struct *mm;
    unsigned long addr = 0;
    int ret;
    spinlock_t *lock;

    ret = kstrtoul(virtual_address, 16, &addr);
    if (ret) {
        printk(KERN_ERR "va_status: Error converting address: %s\n", virtual_address);
        return ret;
    }

    mm = task->mm;

    pgd_t *pgd = pgd_offset(mm, addr);
    pud_t *pud = pud_offset(pgd, addr);
    pmd_t *pmd = pmd_offset(pud, addr);

    pte_t *pte;
    spinlock_t *ptl;
    pte = pte_offset_map_lock(mm, pmd, addr, &ptl);

    if (pte_present(*pte))
        printk(KERN_INFO "va_status: Address %lx is in memory\n", addr);
    else
        printk(KERN_INFO "va_status: Address %lx is on disk or not present\n", addr);

    pte_unmap_unlock(pte, ptl);

    return 0;

}

static void cleanup_mod(void)
{
    printk(KERN_INFO "Removing print_virtual_address_space_module\n");
}

module_init(va_status_mod);
module_exit(cleanup_mod);

MODULE_LICENSE("GPL");