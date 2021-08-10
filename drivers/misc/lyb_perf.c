#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <misc/lyb_perf.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("lybxlpsv");
MODULE_DESCRIPTION("lyb performance driver");
MODULE_VERSION("0.0.1");

int lyb_sconfig = -1;

__read_mostly bool lyb_boost_cpu = false;
__read_mostly bool lyb_boost_devfreq = false;

__read_mostly bool lyb_eff = false;
module_param(lyb_eff, bool, 0644);

__read_mostly bool lyb_boost_def = false;
module_param(lyb_boost_def, bool, 0644);

__read_mostly bool lyb_eff_def = false;
module_param(lyb_eff_def, bool, 0644);

__read_mostly bool lyb_kgsl_skip_zero = false;
module_param(lyb_kgsl_skip_zero, bool, 0644);

__read_mostly int lyb_min_0_l = 1036800;
module_param(lyb_min_0_l, int, 0644);
__read_mostly int lyb_min_0_b = 1056000;
module_param(lyb_min_0_b, int, 0644);
__read_mostly int lyb_min_1_l = 1708800;
module_param(lyb_min_1_l, int, 0644);
__read_mostly int lyb_min_1_b = 1401600;
module_param(lyb_min_1_b, int, 0644);

extern char *saved_command_line;

static int __init lyb_driver_init(void) {
    if (strstr(saved_command_line, "lyb_boost_def=1")) {
		lyb_boost_def = 1;
	}

    if (strstr(saved_command_line, "lyb_eff_def=1")) {
		lyb_eff_def = 1;
	}
    printk(KERN_INFO "lyb_perf initialized");
 return 0;
}

static void __exit lyb_driver_exit(void) {
 printk(KERN_INFO "lyb_perf exit");
}

module_init(lyb_driver_init);
module_exit(lyb_driver_exit);