#include <linux/module.h>
#include <linux/slab.h>
#include <linux/pci.h>

#include "print_variables.h"

void print_my_homework(void)
{
    char *mem_chunk;

    mem_chunk = kmalloc(1000, GFP_KERNEL);
    if (NULL == mem_chunk) {
        printk(KERN_INFO "kmalloc failed! Finishing...\n");
        return;
    }
    printk(KERN_INFO "Memory chunk address:       %p\n", mem_chunk);
    printk(KERN_INFO "mem_chunk variable address: %p\n", &mem_chunk);
    printk(KERN_INFO "jiffies address is '%p'\n", &jiffies);

    printk(KERN_INFO "%pf address: %p\n",
                        &print_my_homework, &print_my_homework);
    printk(KERN_INFO "%pf address: %p\n",
                        &__pci_register_driver, &__pci_register_driver);
    printk(KERN_INFO "Return name + offset: %pS\n", __builtin_return_address(0));

    kfree(mem_chunk);
}