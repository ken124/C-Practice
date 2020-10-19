#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/err.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "testchar"
#define CLASS_NAME "test"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Chris");
MODULE_DESCRIPTION("A simple linux char driver");
MODULE_VERSION("0.1");

static int majorNumber;
static char message[256] = {0};
static short size_of_message;
static int numberOpens = 0;
static struct class* testcharClass = NULL;
static struct device* testcharDevice = NULL;

static int dev_open(struct inode *, struct file *);
static int dev_release(struct inode *, struct file *);
static ssize_t dev_read(struct file *, char *, size_t, loff_t *);
static ssize_t dev_write(struct file *, const char *, size_t, loff_t *);

static struct file_operations fops =
{
  .open = dev_open,
  .read = dev_read,
  .write = dev_write,
  .release = dev_release,
};

static int __init testchar_init(void){
  printk(KERN_INFO "TestChar: Initializing the TestCHar LKM...\n");

  //register major number
  majorNumber = register_chrdev(0, DEVICE_NAME, &fops);
  if (majorNumber < 0) {
    printk(KERN_ALERT "TestChar failed to register a major number...\n");
    return majorNumber;
  }
  printk(KERN_INFO "TestChar: registered correctly with major number %d\n", majorNumber);

  //register device class
  testcharClass = class_create(THIS_MODULE, CLASS_NAME);
  if (IS_ERR(testcharClass)) {
    unregister_chrdev(majorNumber, DEVICE_NAME);
    printk(KERN_ALERT "Failed to register device class...\n");
    return PTR_ERR(testcharClass);
  }
  printk(KERN_INFO "TestChar: device class registed correctly\n");

  //register device driver
  testcharDevice = device_create(testcharClass, NULL, MKDEV(majorNumber, 0), NULL, DEVICE_NAME);
  if (IS_ERR(testcharDevice)) {
    class_destroy(testcharClass);
    unregister_chrdev(majorNumber, DEVICE_NAME);
    printk(KERN_ALERT "Failed to create the device\n");
    return PTR_ERR(testcharDevice);
  }
  printk(KERN_INFO "TestChar: device class created correctly\n");
  return 0;
}

static void __exit testchar_exit(void){
  device_destroy(testcharClass, MKDEV(majorNumber, 0));
  class_unregister(testcharClass);
  class_destroy(testcharClass);
  unregister_chrdev(majorNumber, DEVICE_NAME);
  printk(KERN_INFO "TestChar: Goodbye from the LKM!\n");
}
