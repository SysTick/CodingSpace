//硬件相关层
/* 分配/设置/注册一个 platform_device*/

#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/interrupt.h>
#include <linux/list.h>
#include <linux/timer.h>
#include <linux/init.h>
#include <linux/serial_core.h>
#include <linux/platform_device.h>


//资源
//关于led相关的硬件资源，包括以后需要修改时候，我们只需要修改关于资源部分的就可以
static struct resource led_resource[]{
	[0] = {
		.start = 0x56000050,
		.end   = 0x56000050 + 8 - 1,
		.flags = IORESOURCE_MEM,
	},
	[1] = {
		.start = 4,
		.end   = 4,
		.flags = IORESOURCE_MEM,
	}
};

static void led_release(struct device * dev)
{

}

//定义平台设备
static struct platform_device led_dev = {
	.name	= "myled",
	.id     = -1,
	.num_resources	= ARRAY_SIZE(led_resource),
	.resource 	= led_resource,
	.dev = {
			.release = led_relaease,
		},
};


//入口函数
static int led_dev_init(void)
{
	platform_device_register(&led_dev);		//注册一个platform_device
	return 0;
}

//出口函数
static void led_dev_exit(void)
{
	platform_device_unregister(&led_dev);		//卸载一个platform_device
}

//修饰一下入口函数和出口函数，并加上GPL协议
module_init(led_dev_init);
module_exit(led_dev_exit);

MODULE_LECENSE("GPL");
