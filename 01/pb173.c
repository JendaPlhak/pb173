#include <linux/module.h>
#include <linux/slab.h>

static int my_init(void)
{
	char *mem_chunk;
	pr_info("Hello world\n");

	mem_chunk = kmalloc(1000, GFP_KERNEL);
	if (NULL == mem_chunk) {
		return 1;
	}

	strcpy(mem_chunk, "Bye\n");
	printk(KERN_INFO "%s", mem_chunk);

	kfree(mem_chunk);
	return 0;
}

static void my_exit(void)
{
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
