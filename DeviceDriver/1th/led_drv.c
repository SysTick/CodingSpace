/*分配/设置/注册一个platform_driver*/


#include <linux/module.h>
#include <linux/version.h>

#include <linux/init.h>
#include <linux/fs.h>
#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/sched.h>
#include <linux/pm.h>
#include <linux/sysctl.h>
#include <linux/proc_fs.h>
#include <linux/delay.h>
#include <linux/platform_device.h>
#include <linux/input.h>
#include <linux/irq.h>

static int major;

static struct class *cls;
static volatile unsigned long *gpio_con;    //gpio配置寄存器
static volatile unsigned long *gpio_dat;    //gpio数据寄存器
static int pin;   //led资源引脚

static int led_open(struct inode *inode, struct file *file)
{
    *gpio_con &= ~(0x3 << (pin * 2));
    *gpio_con |= (0x1 << (pin * 2));
    return 0;
}

static ssize_t led_write(struct file *file, const char __user *buf,size_t count,loff_t * ppos)
{
  int val;

  copy_from_user(&val, buf, count);

  if(val == 1)
  {
    *gpio_dat &= ~(1 << pin);
  }
  else
  {
    *gpio_dat |= (1 << pin);
  }

  return 0;
}
//构造一个file_operations结构体
//实现设备的open, write, read
static struct file_operations led_fops = {
    .owmer  = THIS_MODULE,
    .open   = led_open,
    .write  = led_write,
};

//定义led_probe函数
static int led_probe(struct platform_device *pdev)
{

    struct resource *res;

    /*根据platform_device的资源进行ioremap*/
    res = platform_get_resource(pdev, IOREOURCE_MEM, 0);    //内存资源
    gpio_con = ioremap(res->start, res->end - res->start + 1);    // ioremap(起始地址，大小)
    gpio_dat = gpio_con + 1;

    res = platrorm_get_resource(pdev, IORESOURCE_IRQ, 0);   //中断资源
    pin = res->start;
    /*注册字符设备驱动函数*/

    printk("led_probe, found led\n");
    //注册一个字符设备
    major = register_chrdev(0, "myled", led_fops);

    //让系统自动为我们创建设备节点
    cls = class_create(THIS_MODULE, "myled");
    //在/dev 目录下创建名为led的设备节点
    class_device_create(cls, NULL, MKDEV(major, 0), NULL, "led");   /* /dev/led*/

    return 0;
}

//定义led_remove函数
static int led_remove(platform_device *pdev)
{
    /*卸载字符设备驱动程序*/

    /*iounremap*/

    printk("led_remove, remove led\n");

    class_device_destroy(cls, MKDEV(major, 0));
    class_destroy(cls);
    uregister_chrdev(major, "myled");
    iounmap(gpio_con);
    return 0;
}


//定义一个platform_driver结构体
struct platform_driver led_drv = {
    .probe    = led_probe,
    .remove   = led_remove,
    .driver   = {
        //这里的设备名称要和dev里的一致，
        //平台总线里的match函数通过比较他们的名字，
        //内核里面有同名的platform_device和platform_driver时，系统才会调用probe函数
        .name   "myled",
    }
}

//入口函数
static int led_drv_init(void)
{
    platform_driver_register(&led_drv);
    return 0;
}

//出口函数
static void led_drv_exit(void)
{
    platform_driver_unregister(&led_drv);
}

module_init(led_drv_init);
module_exit(led_drv_exit);

MODULE_LECENSE("GPL");
