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

//TQ2440
//nLED_1 GPB5
//nLED_1 GPB6
//nLED_1 GPB7
//nLED_1 GPB8
static struct resource led_resource[]{
	//
	[0] = {
		.start = 0x56000010,	//GPFCON 寄存器地址
		.end   = 0x56000050 + 8 - 1,	// 这个为什么要这么写呢？？
		.flags = IORESOURCE_MEM,	//表明为内存资源
	},
	[1] = {
		.start = 4,		//外部中断4
		.end   = 4,
		.flags = IORESOURCE_IRQ,	//表明为中断资源
	}
};

//定义led_release函数
static void led_release(struct device * dev)
{

}

//定义平台设备
static struct platform_device led_dev = {
	.name	= "myled",		//该平台设备的name
	.id     = -1,		//id
	.num_resources	= ARRAY_SIZE(led_resource),		//定义该平台设备的资源
	.resource 	= led_resource,
	.dev = {
			.release = led_relaease,		//
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

//修饰一下入口函数和出口函数，并加上GPL协议,不加会报错
module_init(led_dev_init);
module_exit(led_dev_exit);

MODULE_LECENSE("GPL");
