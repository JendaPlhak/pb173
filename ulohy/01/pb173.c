#include <linux/module.h>
#include <linux/slab.h>
#include <linux/pci.h>


static int my_init(void)
{
	char *mem_chunk;

	mem_chunk = kmalloc(1000, GFP_KERNEL);
	if (NULL == mem_chunk) {
		return 1;
	}
	printk(KERN_INFO "Memory chunk address:       %p\n", mem_chunk);
	printk(KERN_INFO "mem_chunk variable address: %p\n", &mem_chunk);
	printk(KERN_INFO "'%pf' address is '%p'\n", &my_init, &my_init);
	printk(KERN_INFO "'%pf' address is '%p'\n", &__pci_register_driver,
							&__pci_register_driver);
	printk(KERN_INFO "jiffies address is '%p'\n", &jiffies);

	kfree(mem_chunk);
	return 0;
}

static void my_exit(void)
{
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
