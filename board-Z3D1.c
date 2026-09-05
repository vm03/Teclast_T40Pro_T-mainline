/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2026, Akari Tsuyukusa <akkun11.open@gmail.com>
 */

#include <board.h>
#include <drivers/framework.h>
#include <lib/simplefb.h>

#ifdef CONFIG_SIMPLE_FB
static struct video_info Z3D1_fb = {
	.format = FB_FORMAT_RGB565,
	.width = 1200,
	.height = 2000,
	.stride = 2,
	.address = (void *)0x9e000000,
	.scale = 2,
};
#endif

int Z3D1_drv(void)
{
#ifdef CONFIG_SIMPLE_FB
	REGISTER_DRIVER("simplefb", simplefb_probe, &Z3D1_fb);
#endif
	return 0;
}

struct board_data board_ops = {
	.name = "teclast-Z3D1",
	.ops = {
		.drivers_init = Z3D1_drv
	},
	.quirks = 0
};
