/*
 * Copyright (c) 2021 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#include <zephyr/kernel.h>
#include <mgmt/fmfu_mgmt.h>
#include <mgmt/fmfu_mgmt_stat.h>
#include <modem/modem_info.h>
#include <modem/nrf_modem_lib.h>
#include <zephyr/dfu/mcuboot.h>

int main(void)
{
	int err = 0;

	nrf_modem_lib_bootloader_init();
	/* Register SMP Communication stats */
	fmfu_mgmt_stat_init();
	/* Initialize MCUMgr handlers for full modem update */
	err = fmfu_mgmt_init();
	if (err) {
		printk("Error in fmfu init: %d\n\r", err);
	}
	printk("Initialized and ready to receive firmware\n\r");
	if (boot_is_img_confirmed()) {
		printk("Current image confirmed\n\r");
	} else {
		printk("Current image not confirmed yet\n\r");
	}

	return 0;
}
