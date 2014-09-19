#include <linux/module.h>
#include <linux/slab.h>
#include <linux/pci.h>

#include "print_variables.h"


static int my_init(void)
{
	printk(KERN_INFO "-------------First homework-------------\n");
	print_my_homework();
	return 0;
}

static void my_exit(void)
{
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
