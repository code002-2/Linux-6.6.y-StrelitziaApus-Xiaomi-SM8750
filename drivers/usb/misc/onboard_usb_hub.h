/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (c) 2022, Google LLC
 */

#ifndef _USB_MISC_ONBOARD_USB_HUB_H
#define _USB_MISC_ONBOARD_USB_HUB_H

struct onboard_hub_pdata {
	unsigned long reset_us;		/* reset pulse width in us */
	unsigned int num_supplies;	/* number of supplies */
	/* Per-chip supply names; NULL means use the generic vdd/vdd2 pair. */
	const char * const *supply_names;
};

static const struct onboard_hub_pdata microchip_usb424_data = {
	.reset_us = 1,
	.num_supplies = 1,
};

static const struct onboard_hub_pdata microchip_usb5744_data = {
	.reset_us = 0,
	.num_supplies = 2,
};

static const struct onboard_hub_pdata realtek_rts5411_data = {
	.reset_us = 0,
	.num_supplies = 1,
};

static const struct onboard_hub_pdata ti_tusb8041_data = {
	.reset_us = 3000,
	.num_supplies = 1,
};

static const struct onboard_hub_pdata cypress_hx3_data = {
	.reset_us = 10000,
	.num_supplies = 2,
};

static const struct onboard_hub_pdata genesys_gl850g_data = {
	.reset_us = 3,
	.num_supplies = 1,
};

static const struct onboard_hub_pdata genesys_gl852g_data = {
	.reset_us = 50,
	.num_supplies = 1,
};

static const struct onboard_hub_pdata vialab_vl817_data = {
	.reset_us = 10,
	.num_supplies = 1,
};

/*
 * The WCH CH334/CH335 4-port USB2.0 hub needs a 14 ms reset pulse after its
 * supplies come up; releasing reset earlier leaves the chip unconfigured and
 * the port then dies with EPROTO (-71).
 */
static const char * const wch_ch334_supply_names[] = { "vdd33", "v5" };

static const struct onboard_hub_pdata wch_ch334_data = {
	.reset_us = 14000,
	.num_supplies = 2,
	.supply_names = wch_ch334_supply_names,
};

static const struct of_device_id onboard_hub_match[] = {
	{ .compatible = "usb424,2412", .data = &microchip_usb424_data, },
	{ .compatible = "usb424,2514", .data = &microchip_usb424_data, },
	{ .compatible = "usb424,2517", .data = &microchip_usb424_data, },
	{ .compatible = "usb424,2744", .data = &microchip_usb5744_data, },
	{ .compatible = "usb424,5744", .data = &microchip_usb5744_data, },
	{ .compatible = "usb451,8140", .data = &ti_tusb8041_data, },
	{ .compatible = "usb451,8142", .data = &ti_tusb8041_data, },
	{ .compatible = "usb4b4,6504", .data = &cypress_hx3_data, },
	{ .compatible = "usb4b4,6506", .data = &cypress_hx3_data, },
	{ .compatible = "usb5e3,608", .data = &genesys_gl850g_data, },
	{ .compatible = "usb5e3,610", .data = &genesys_gl852g_data, },
	{ .compatible = "usb5e3,620", .data = &genesys_gl852g_data, },
	{ .compatible = "usbbda,411", .data = &realtek_rts5411_data, },
	{ .compatible = "usbbda,5411", .data = &realtek_rts5411_data, },
	{ .compatible = "usbbda,414", .data = &realtek_rts5411_data, },
	{ .compatible = "usbbda,5414", .data = &realtek_rts5411_data, },
	{ .compatible = "usb1a86,8091", .data = &wch_ch334_data, },
	{ .compatible = "usb2109,817", .data = &vialab_vl817_data, },
	{ .compatible = "usb2109,2817", .data = &vialab_vl817_data, },
	{}
};

#endif /* _USB_MISC_ONBOARD_USB_HUB_H */
