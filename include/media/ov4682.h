/*
 * ov4682.h - ov4682 sensor driver
 *
 * Copyright (c) 2014 NVIDIA Corporation.  All rights reserved.
 *
 * Contributors:
 *  Jerry Chang <jerchang@nvidia.com>
 *
 * This file is licensed under the terms of the GNU General Public License
 * version 2. This program is licensed "as is" without any warranty of any
 * kind, whether express or implied.
 */

#ifndef __OV4682_H__
#define __OV4682_H__

#include <linux/ioctl.h>
#include <misc/sensor-hub-msg.h>

#define OV4682_IOCTL_SET_MODE	_IOW('o', 1, struct ov4682_mode)
#define OV4682_IOCTL_SET_FRAME_LENGTH	_IOW('o', 2, __u32)
#define OV4682_IOCTL_SET_COARSE_TIME	_IOW('o', 3, __u32)
#define OV4682_IOCTL_SET_GAIN	_IOW('o', 4, __u16)
#define OV4682_IOCTL_GET_STATUS	_IOR('o', 5, __u8)
#define OV4682_IOCTL_SET_GROUP_HOLD	_IOW('o', 6, struct ov4682_grouphold)
#define OV4682_IOCTL_GET_FUSEID	_IOR('o', 7, struct ov4682_sensordata)
#define OV4682_IOCTL_SET_FLASH	_IOW('o', 8, struct ov4682_flash_control)
#define OV4682_IOCTL_START_STREAM _IO('o', 9)
#define OV4682_IOCTL_GET_FRAMEINFO _IOWR('o', 10, struct frameinfo)

struct ov4682_sensordata {
	__u32 fuse_id_size;
	__u8 fuse_id[16];
};

struct ov4682_mode {
	int xres;
	int yres;
	int fps;
	__u32 frame_length;
	__u32 coarse_time;
	__u16 gain;
};

struct ov4682_grouphold {
	__u32	frame_length;
	__u8	frame_length_enable;
	__u32	coarse_time;
	__u8	coarse_time_enable;
	__s32	gain;
	__u8	gain_enable;
};

struct ov4682_flash_control {
	__u8 enable;
	__u8 power;
	__u8 delay;
};

#ifdef __KERNEL__
struct ov4682_power_rail {
	struct regulator *avdd_af;
	struct regulator *avdd_hv;
	struct regulator *vdd_lv;
	struct regulator *dvdd;
};

struct ov4682_platform_data {
	int (*power_on)(struct ov4682_power_rail *pw, unsigned char sh_device);
	int (*power_off)(struct ov4682_power_rail *pw, unsigned char sh_device);
	const char *mclk_name;
	unsigned char sh_device;
};
#endif /* __KERNEL__ */

#endif /* __OV4682_H__ */
