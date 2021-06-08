#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <misc/lyb_perf.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("lybxlpsv");
MODULE_DESCRIPTION("lyb performance driver");
MODULE_VERSION("0.0.1");

int lyb_sconfig = -1;

bool lyb_boost_cpu = false;
bool lyb_boost_devfreq = false;

bool lyb_eff = false;
module_param(lyb_eff, bool, 0644);

bool lyb_boost_def = false;
module_param(lyb_boost_def, bool, 0644);

bool lyb_eff_def = false;
module_param(lyb_eff_def, bool, 0644);

int lyb_min_1_l = 1708800;
int lyb_min_1_b = 1401600;

static int __init lyb_driver_init(void) {
 printk(KERN_INFO "lyb_perf initialized");
 return 0;
}

static void __exit lyb_driver_exit(void) {
 printk(KERN_INFO "lyb_perf exit");
}

module_init(lyb_driver_init);
module_exit(lyb_driver_exit);