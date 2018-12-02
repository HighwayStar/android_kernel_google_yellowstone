/*
 * bq2477x-charger.h -- BQ2477X Charger driver
 *
 * Copyright (c) 2013, NVIDIA CORPORATION.  All rights reserved.
 *
 * Author: Andy Park <andyp@nvidia.com>
 * Author: Syed Rafiuddin <srafiuddin@nvidia.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 */

#ifndef __LINUX_POWER_BQ2477X_CHARGER_H
#define __LINUX_POWER_BQ2477X_CHARGER_H

/* Register definitions */
#define BQ2477X_CHARGE_OPTION_0_LSB		0x00
#define BQ2477X_CHARGE_OPTION_0_MSB		0x01
#define BQ2477X_CHARGE_OPTION_1_LSB		0x02
#define BQ2477X_CHARGE_OPTION_1_MSB		0x03
#define BQ2477X_PROCHOT_OPTION_0_LSB		0x04
#define BQ2477X_PROCHOT_OPTION_0_MSB		0x05
#define BQ2477X_PROCHOT_OPTION_1_LSB		0x06
#define BQ2477X_PROCHOT_OPTION_1_MSB		0x07
#define BQ2477X_CHARGE_CURRENT_LSB		0x0A
#define BQ2477X_CHARGE_CURRENT_MSB		0x0B
#define BQ2477X_MAX_CHARGE_VOLTAGE_LSB		0x0C
#define BQ2477X_MAX_CHARGE_VOLTAGE_MSB		0x0D
#define BQ2477X_MIN_SYS_VOLTAGE			0x0E
#define BQ2477X_INPUT_CURRENT			0x0F
#define BQ2477X_DEVICE_ADDR_REG			0x09

#define BQ24770_DEVICE_ID_PG_1_0		0x14
#define BQ24770_DEVICE_ID_PG_1_1		0x114
#define BQ24773_DEVICE_ID_PG_1_0		0x40
#define BQ24773_DEVICE_ID_PG_1_1		0x41

#define BQ2477X_CHARGE_OPTION_POR_LSB		0x0E
#define BQ2477X_CHARGE_OPTION_POR_MSB		0x81

#define BQ2477X_CHARGE_CURRENT_SHIFT		6
#define BQ2477X_MAX_CHARGE_VOLTAGE_SHIFT	4
#define BQ2477X_MIN_SYS_VOLTAGE_SHIFT		8
#define BQ2477X_INPUT_CURRENT_SHIFT		6

#define BQ2477X_ENABLE_CHARGE_MASK		BIT(0)
#define BQ2477X_WATCHDOG_TIMER			0x60
#define BQ2477X_CHARGE_ENABLE			0x01
#define BQ2477X_LEARN_MODE 		0x20


#define BQ2477X_MAX_REGS			(BQ2477X_DEVICE_ADDR_REG + 1)

struct bq2477x_charge_zone {
	int min_temp;
	int max_temp;
	int charge_voltage;
	int charge_current;
};

struct bq2477x_platform_data {
	int     irq;
	int     dac_ctrl;
	int     dac_v;
	int     dac_minsv;
	int     wdt_refresh_timeout;
	int	acok_gpio;
	int     dock_12v_gpio;
	int     dock_12v_gpio_active_high;
	int	dock_usb3_gpio;
	int	dock_usb3_active_high;
	int	dock_max_ua;
	int	disable_vbus_12v_boost_gpio;
	int	max_charge_ua;
	char	*extcon_dock_name;
	int	num_consumer_supplies;
	struct	regulator_consumer_supply *consumer_supplies;
	u32	*chg_current_limit;
	const struct  bq2477x_charge_zone *charge_table;
};
#endif /* __LINUX_POWER_BQ2477X_CHARGER_H */
