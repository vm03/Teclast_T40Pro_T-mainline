// SPDX-License-Identifier: GPL-2.0-only
/*
 * Driver generated from the Spreadtrum/Unisoc device tree node
 * "lcd_ft8201e_TLCM_HJR104017D_A1_mipi_2k".
 *
 * Original DTS source: stok.dts
 *
 * Panel:
 *   FT8201E / TLCM HJR104017D A1
 *   1200 x 2000, 4-lane MIPI DSI, RGB888
 *
 * The Spreadtrum DT command format is:
 *   [data_type, delay_ms, word_count_hi, word_count_lo, payload...]
 *
 * The original Unisoc generic panel driver uses only the payload length when
 * transmitting commands and uses mipi_dsi_generic_write() when
 * "sprd,use-dcs-write" is absent. This panel has no "sprd,use-dcs-write"
 * property, so the generated driver intentionally uses generic writes for
 * the initialization and sleep command sequences.
 */

#include <linux/delay.h>
#include <linux/gpio/consumer.h>
#include <linux/module.h>
#include <linux/workqueue.h>
#include <linux/of.h>

#include <drm/drm_mipi_dsi.h>
#include <drm/drm_modes.h>
#include <drm/drm_panel.h>
#include <drm/drm_probe_helper.h>

struct ft8201e_panel {
	struct drm_panel panel;
	struct mipi_dsi_device *dsi;
	struct gpio_desc *reset_gpio;
};

static inline struct ft8201e_panel *
to_ft8201e_panel(struct drm_panel *panel)
{
	return container_of(panel, struct ft8201e_panel, panel);
}

static void ft8201e_panel_reset(struct ft8201e_panel *ctx)
{
	/* Original sprd,reset-on-sequence: <1 10> <0 20> <1 130>. */
	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	msleep(10);
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	msleep(20);
	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	msleep(130);
}

static void ft8201e_panel_reset_off(struct ft8201e_panel *ctx)
{
	/* Original sprd,reset-off-sequence: <0 20>. */
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	msleep(20);
}

static int ft8201e_panel_on(struct ft8201e_panel *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	/* #000 @ +0x0000: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	/* #001 @ +0x0006: DT=0x39, len=4, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xff, 0x82, 0x01, 0x01);
	/* #002 @ +0x000e: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x80);
	/* #003 @ +0x0014: DT=0x39, len=3, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xff, 0x82, 0x01);
	/* #004 @ +0x001b: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x93);
	/* #005 @ +0x0021: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0x66);
	/* #006 @ +0x0027: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x97);
	/* #007 @ +0x002d: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0x66);
	/* #008 @ +0x0033: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x9e);
	/* #009 @ +0x0039: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0x0a);
	/* #010 @ +0x003f: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x9a);
	/* #011 @ +0x0045: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0xd7);
	/* #012 @ +0x004b: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x9c);
	/* #013 @ +0x0051: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0xd7);
	/* #014 @ +0x0057: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xb6);
	/* #015 @ +0x005d: DT=0x39, len=3, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0x5c, 0x5c);
	/* #016 @ +0x0064: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xb8);
	/* #017 @ +0x006a: DT=0x39, len=3, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0x4d, 0x4d);
	/* #018 @ +0x0071: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	/* #019 @ +0x0077: DT=0x39, len=3, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xd8, 0xc8, 0xc8);
	/* #020 @ +0x007e: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x82);
	/* #021 @ +0x0084: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0x95);
	/* #022 @ +0x008a: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x83);
	/* #023 @ +0x0090: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0x07);
	/* #024 @ +0x0096: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	/* #025 @ +0x009c: DT=0x39, len=17, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe1, 0x05, 0x0f, 0x26, 0x3a, 0x45, 0x51, 0x62, 0x71, 0x71, 0x7e, 0x7e, 0x90, 0x76, 0x65, 0x66, 0x5b);
	/* #026 @ +0x00b1: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x10);
	/* #027 @ +0x00b7: DT=0x39, len=9, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe1, 0x53, 0x47, 0x38, 0x2f, 0x27, 0x18, 0x05, 0x00);
	/* #028 @ +0x00c4: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	/* #029 @ +0x00ca: DT=0x39, len=17, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe2, 0x05, 0x0f, 0x26, 0x3a, 0x45, 0x51, 0x62, 0x71, 0x71, 0x7e, 0x7e, 0x90, 0x76, 0x65, 0x66, 0x5b);
	/* #030 @ +0x00df: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x10);
	/* #031 @ +0x00e5: DT=0x39, len=9, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xe2, 0x53, 0x47, 0x38, 0x2f, 0x27, 0x18, 0x05, 0x00);
	/* #032 @ +0x00f2: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x84);
	/* #033 @ +0x00f8: DT=0x39, len=3, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0x88, 0x88);
	/* #034 @ +0x00ff: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x80);
	/* #035 @ +0x0105: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xa4, 0x0c);
	/* #036 @ +0x010b: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xa0);
	/* #037 @ +0x0111: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf3, 0x10);
	/* #038 @ +0x0117: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xa1);
	/* #039 @ +0x011d: DT=0x39, len=3, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb3, 0x04, 0xb0);
	/* #040 @ +0x0124: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xa3);
	/* #041 @ +0x012a: DT=0x39, len=3, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb3, 0x07, 0xd0);
	/* #042 @ +0x0131: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xa5);
	/* #043 @ +0x0137: DT=0x39, len=3, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xb3, 0x80, 0x13);
	/* #044 @ +0x013e: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xd0);
	/* #045 @ +0x0144: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc1, 0xb0);
	/* #046 @ +0x014a: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x80);
	/* #047 @ +0x0150: DT=0x39, len=8, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb, 0x33, 0x33, 0x30, 0x33, 0x30, 0x33, 0x30);
	/* #048 @ +0x015c: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x87);
	/* #049 @ +0x0162: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb, 0x33);
	/* #050 @ +0x0168: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x88);
	/* #051 @ +0x016e: DT=0x39, len=9, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb, 0x33, 0x33, 0x33, 0x33, 0x33, 0x30, 0x33, 0x33);
	/* #052 @ +0x017b: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x90);
	/* #053 @ +0x0181: DT=0x39, len=8, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb, 0x30, 0x33, 0x33, 0x33, 0x30, 0x30, 0x33);
	/* #054 @ +0x018d: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x97);
	/* #055 @ +0x0193: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb, 0x33);
	/* #056 @ +0x0199: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x98);
	/* #057 @ +0x019f: DT=0x39, len=9, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04);
	/* #058 @ +0x01ac: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xa0);
	/* #059 @ +0x01b2: DT=0x39, len=9, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04);
	/* #060 @ +0x01bf: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xa8);
	/* #061 @ +0x01c5: DT=0x39, len=9, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04);
	/* #062 @ +0x01d2: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xb0);
	/* #063 @ +0x01d8: DT=0x39, len=8, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
	/* #064 @ +0x01e4: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xb7);
	/* #065 @ +0x01ea: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb, 0x00);
	/* #066 @ +0x01f0: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xb8);
	/* #067 @ +0x01f6: DT=0x39, len=9, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
	/* #068 @ +0x0203: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xc0);
	/* #069 @ +0x0209: DT=0x39, len=8, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
	/* #070 @ +0x0215: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xc7);
	/* #071 @ +0x021b: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb, 0x00);
	/* #072 @ +0x0221: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x80);
	/* #073 @ +0x0227: DT=0x39, len=9, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcc, 0x00, 0x00, 0x00, 0x38, 0x38, 0x29, 0x2a, 0x34);
	/* #074 @ +0x0234: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x88);
	/* #075 @ +0x023a: DT=0x39, len=9, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcc, 0x35, 0x13, 0x14, 0x15, 0x16, 0x07, 0x1f, 0x00);
	/* #076 @ +0x0247: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x90);
	/* #077 @ +0x024d: DT=0x39, len=7, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcc, 0x00, 0x00, 0x00, 0x38, 0x38, 0x38);
	/* #078 @ +0x0258: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x80);
	/* #079 @ +0x025e: DT=0x39, len=9, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcd, 0x00, 0x00, 0x00, 0x38, 0x38, 0x29, 0x2a, 0x34);
	/* #080 @ +0x026b: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x88);
	/* #081 @ +0x0271: DT=0x39, len=9, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcd, 0x35, 0x17, 0x18, 0x19, 0x1a, 0x08, 0x20, 0x00);
	/* #082 @ +0x027e: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x90);
	/* #083 @ +0x0284: DT=0x39, len=7, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcd, 0x00, 0x00, 0x00, 0x38, 0x38, 0x38);
	/* #084 @ +0x028f: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xa0);
	/* #085 @ +0x0295: DT=0x39, len=9, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcc, 0x00, 0x00, 0x00, 0x38, 0x38, 0x29, 0x2a, 0x34);
	/* #086 @ +0x02a2: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xa8);
	/* #087 @ +0x02a8: DT=0x39, len=9, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcc, 0x35, 0x1a, 0x19, 0x18, 0x17, 0x20, 0x08, 0x00);
	/* #088 @ +0x02b5: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xb0);
	/* #089 @ +0x02bb: DT=0x39, len=7, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcc, 0x00, 0x00, 0x00, 0x38, 0x38, 0x38);
	/* #090 @ +0x02c6: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xa0);
	/* #091 @ +0x02cc: DT=0x39, len=9, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcd, 0x00, 0x00, 0x00, 0x38, 0x38, 0x29, 0x2a, 0x34);
	/* #092 @ +0x02d9: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xa8);
	/* #093 @ +0x02df: DT=0x39, len=9, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcd, 0x35, 0x16, 0x15, 0x14, 0x13, 0x1f, 0x07, 0x00);
	/* #094 @ +0x02ec: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xb0);
	/* #095 @ +0x02f2: DT=0x39, len=7, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcd, 0x00, 0x00, 0x00, 0x38, 0x38, 0x38);
	/* #096 @ +0x02fd: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x81);
	/* #097 @ +0x0303: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc2, 0x40);
	/* #098 @ +0x0309: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x90);
	/* #099 @ +0x030f: DT=0x39, len=5, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc2, 0x85, 0x03, 0x78, 0x9d);
	/* #100 @ +0x0318: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x94);
	/* #101 @ +0x031e: DT=0x39, len=5, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc2, 0x84, 0x03, 0x78, 0x9d);
	/* #102 @ +0x0327: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xb0);
	/* #103 @ +0x032d: DT=0x39, len=5, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc2, 0x01, 0x43, 0x78, 0x9d);
	/* #104 @ +0x0336: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xb4);
	/* #105 @ +0x033c: DT=0x39, len=5, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc2, 0x00, 0x03, 0x78, 0x9d);
	/* #106 @ +0x0345: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x80);
	/* #107 @ +0x034b: DT=0x39, len=9, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc3, 0x83, 0x86, 0x13, 0x75, 0x9d, 0x00, 0x02, 0x07);
	/* #108 @ +0x0358: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x88);
	/* #109 @ +0x035e: DT=0x39, len=9, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc3, 0x81, 0x84, 0x13, 0x75, 0x9d, 0x00, 0x02, 0x07);
	/* #110 @ +0x036b: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x90);
	/* #111 @ +0x0371: DT=0x39, len=9, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc3, 0x01, 0x82, 0x13, 0x75, 0x9d, 0x00, 0x02, 0x07);
	/* #112 @ +0x037e: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x98);
	/* #113 @ +0x0384: DT=0x39, len=9, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc3, 0x03, 0x00, 0x13, 0x75, 0x9d, 0x00, 0x02, 0x07);
	/* #114 @ +0x0391: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xc0);
	/* #115 @ +0x0397: DT=0x39, len=9, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcd, 0x82, 0x85, 0x13, 0x75, 0x9d, 0x00, 0x02, 0x07);
	/* #116 @ +0x03a4: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xc8);
	/* #117 @ +0x03aa: DT=0x39, len=9, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcd, 0x00, 0x83, 0x13, 0x75, 0x9d, 0x00, 0x02, 0x07);
	/* #118 @ +0x03b7: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xd0);
	/* #119 @ +0x03bd: DT=0x39, len=9, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcd, 0x02, 0x81, 0x13, 0x75, 0x9d, 0x00, 0x02, 0x07);
	/* #120 @ +0x03ca: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xd8);
	/* #121 @ +0x03d0: DT=0x39, len=9, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcd, 0x04, 0x01, 0x13, 0x75, 0x9d, 0x00, 0x02, 0x07);
	/* #122 @ +0x03dd: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xe2);
	/* #123 @ +0x03e3: DT=0x39, len=5, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcc, 0x08, 0x7c, 0x00, 0x08);
	/* #124 @ +0x03ec: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xf0);
	/* #125 @ +0x03f2: DT=0x39, len=6, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcc, 0x3d, 0x88, 0x88, 0xd0, 0x65);
	/* #126 @ +0x03fc: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xfd);
	/* #127 @ +0x0402: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcb, 0x82);
	/* #128 @ +0x0408: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x80);
	/* #129 @ +0x040e: DT=0x39, len=7, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc0, 0x00, 0x91, 0x01, 0x17, 0x00, 0x10);
	/* #130 @ +0x0419: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x90);
	/* #131 @ +0x041f: DT=0x39, len=7, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc0, 0x00, 0x91, 0x01, 0x17, 0x00, 0x10);
	/* #132 @ +0x042a: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xa0);
	/* #133 @ +0x0430: DT=0x39, len=7, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc0, 0x01, 0x30, 0x01, 0x17, 0x00, 0x10);
	/* #134 @ +0x043b: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xb0);
	/* #135 @ +0x0441: DT=0x39, len=6, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc0, 0x00, 0x91, 0x01, 0x17, 0x10);
	/* #136 @ +0x044b: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xa3);
	/* #137 @ +0x0451: DT=0x39, len=4, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc1, 0x28, 0x28, 0x04);
	/* #138 @ +0x0459: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x80);
	/* #139 @ +0x045f: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xce, 0x00);
	/* #140 @ +0x0465: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xd0);
	/* #141 @ +0x046b: DT=0x39, len=9, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xce, 0x01, 0x00, 0x0a, 0x01, 0x01, 0x00, 0xf7, 0x00);
	/* #142 @ +0x0478: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xe0);
	/* #143 @ +0x047e: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xce, 0x00);
	/* #144 @ +0x0484: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xf0);
	/* #145 @ +0x048a: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xce, 0x00);
	/* #146 @ +0x0490: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xb0);
	/* #147 @ +0x0496: DT=0x39, len=5, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcf, 0x06, 0x06, 0xba, 0xbe);
	/* #148 @ +0x049f: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xb5);
	/* #149 @ +0x04a5: DT=0x39, len=5, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcf, 0x04, 0x04, 0x40, 0x44);
	/* #150 @ +0x04ae: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xc0);
	/* #151 @ +0x04b4: DT=0x39, len=5, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcf, 0x07, 0x07, 0xb4, 0xb8);
	/* #152 @ +0x04bd: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xc5);
	/* #153 @ +0x04c3: DT=0x39, len=5, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcf, 0x00, 0x07, 0x08, 0xd0);
	/* #154 @ +0x04cc: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x90);
	/* #155 @ +0x04d2: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc4, 0x88);
	/* #156 @ +0x04d8: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x92);
	/* #157 @ +0x04de: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc4, 0xc0);
	/* #158 @ +0x04e4: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xc8);
	/* #159 @ +0x04ea: DT=0x39, len=4, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc3, 0xee, 0xe0, 0x00);
	/* #160 @ +0x04f2: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xc9);
	/* #161 @ +0x04f8: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xce, 0x00);
	/* #162 @ +0x04fe: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x1c, 0x00);
	/* #163 @ +0x0504: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xd6);
	/* #164 @ +0x050a: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc1, 0x00);
	/* #165 @ +0x0510: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xd5);
	/* #166 @ +0x0516: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc0, 0xf0);
	/* #167 @ +0x051c: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xa0);
	/* #168 @ +0x0522: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc1, 0xe0);
	/* #169 @ +0x0528: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x9f);
	/* #170 @ +0x052e: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0x00);
	/* #171 @ +0x0534: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x91);
	/* #172 @ +0x053a: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0x4c);
	/* #173 @ +0x0540: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xd7);
	/* #174 @ +0x0546: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xce, 0x01);
	/* #175 @ +0x054c: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x98);
	/* #176 @ +0x0552: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0x67);
	/* #177 @ +0x0558: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x82);
	/* #178 @ +0x055e: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xa5, 0x01);
	/* #179 @ +0x0564: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x8c);
	/* #180 @ +0x056a: DT=0x39, len=3, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xcf, 0x40, 0x40);
	/* #181 @ +0x0571: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xa4);
	/* #182 @ +0x0577: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf3, 0x0b);
	/* #183 @ +0x057d: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	/* #184 @ +0x0583: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xfa, 0x02);
	/* #185 @ +0x0589: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xa8);
	/* #186 @ +0x058f: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0x09);
	/* #187 @ +0x0595: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xcb);
	/* #188 @ +0x059b: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0x01);
	/* #189 @ +0x05a1: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xb6);
	/* #190 @ +0x05a7: DT=0x39, len=3, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0x5c, 0x5c);
	/* #191 @ +0x05ae: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xb8);
	/* #192 @ +0x05b4: DT=0x39, len=3, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0x4d, 0x4d);
	/* #193 @ +0x05bb: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x91);
	/* #194 @ +0x05c1: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xa5, 0x00);
	/* #195 @ +0x05c7: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xa4);
	/* #196 @ +0x05cd: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf3, 0x0b);
	/* #197 @ +0x05d3: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	/* #198 @ +0x05d9: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xfa, 0x5a);
	/* #199 @ +0x05df: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xa4);
	/* #200 @ +0x05e5: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf3, 0x0b);
	/* #201 @ +0x05eb: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	/* #202 @ +0x05f1: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xfa, 0x01);
	/* #203 @ +0x05f7: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xa8);
	/* #204 @ +0x05fd: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0x00);
	/* #205 @ +0x0603: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xcb);
	/* #206 @ +0x0609: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0x00);
	/* #207 @ +0x060f: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xb6);
	/* #208 @ +0x0615: DT=0x39, len=3, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0x5a, 0x5a);
	/* #209 @ +0x061c: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xb8);
	/* #210 @ +0x0622: DT=0x39, len=3, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xc5, 0x4b, 0x4b);
	/* #211 @ +0x0629: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x91);
	/* #212 @ +0x062f: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xa5, 0x40);
	/* #213 @ +0x0635: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0xa4);
	/* #214 @ +0x063b: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xf3, 0x0b);
	/* #215 @ +0x0641: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	/* #216 @ +0x0647: DT=0x23, len=2, delay=0 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0xfa, 0x5a);
	/* #217 @ +0x064d: DT=0x13, len=1, delay=16 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x11);
	mipi_dsi_msleep(&dsi_ctx, 16);
	/* #218 @ +0x0652: DT=0x13, len=1, delay=20 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x29);
	mipi_dsi_msleep(&dsi_ctx, 20);

	return dsi_ctx.accum_err;
}

static int ft8201e_panel_off(struct ft8201e_panel *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	/* DT=0x13, len=1, delay=10 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x28);
	mipi_dsi_msleep(&dsi_ctx, 10);
	/* DT=0x13, len=1, delay=120 ms */
	mipi_dsi_generic_write_seq_multi(&dsi_ctx, 0x10);
	mipi_dsi_msleep(&dsi_ctx, 120);

	return dsi_ctx.accum_err;
}

static int ft8201e_panel_prepare(struct drm_panel *panel)
{
	struct ft8201e_panel *ctx = to_ft8201e_panel(panel);
        int ret;

	ft8201e_panel_reset(ctx);

        ret = ft8201e_panel_on(ctx);
        if (ret < 0) {
                dev_err(&ctx->dsi->dev, "failed to initialize panel: %d\n", ret);
                return ret;
        }

	return 0;
}

static int ft8201e_panel_unprepare(struct drm_panel *panel)
{
	struct ft8201e_panel *ctx = to_ft8201e_panel(panel);
	int ret;

	ret = ft8201e_panel_off(ctx);
	ft8201e_panel_reset_off(ctx);

	return ret;
}

static const struct drm_display_mode ft8201e_panel_mode = {
	.clock = 153600,
	.hdisplay = 1200,
	.hsync_start = 1206,
	.hsync_end = 1211,
	.htotal = 1243,
	.vdisplay = 2000,
	.vsync_start = 2255,
	.vsync_end = 2261,
	.vtotal = 2295,
	.width_mm = 135,
	.height_mm = 226,
	.type = DRM_MODE_TYPE_DRIVER,
};

static int ft8201e_panel_get_modes(struct drm_panel *panel,
				       struct drm_connector *connector)
{
	return drm_connector_helper_get_modes_fixed(connector,
						   &ft8201e_panel_mode);
}

static const struct drm_panel_funcs ft8201e_panel_funcs = {
	.prepare = ft8201e_panel_prepare,
	.unprepare = ft8201e_panel_unprepare,
	.get_modes = ft8201e_panel_get_modes,
};

static int ft8201e_panel_probe(struct mipi_dsi_device *dsi)
{
	struct device *dev = &dsi->dev;
	struct ft8201e_panel *ctx;
	int ret;

	ctx = devm_kzalloc(dev, sizeof(*ctx), GFP_KERNEL);
	if (!ctx)
		return -ENOMEM;

	ctx->dsi = dsi;

	ctx->reset_gpio = devm_gpiod_get(dev, "reset", GPIOD_OUT_LOW);
	if (IS_ERR(ctx->reset_gpio))
		return dev_err_probe(dev, PTR_ERR(ctx->reset_gpio),
				     "failed to get reset GPIO\n");

	dsi->lanes = 4;
	dsi->format = MIPI_DSI_FMT_RGB888;
	dsi->mode_flags = MIPI_DSI_MODE_VIDEO |
			  MIPI_DSI_MODE_VIDEO_BURST;
	dsi->hs_rate = 1105000000ULL;
	dsi->lp_rate = 20000000ULL;

	mipi_dsi_set_drvdata(dsi, ctx);

	drm_panel_init(&ctx->panel, dev, &ft8201e_panel_funcs,
			DRM_MODE_CONNECTOR_DSI);
	ctx->panel.prepare_prev_first = true;

	ret = drm_panel_of_backlight(&ctx->panel);
	if (ret)
		return dev_err_probe(dev, ret, "Failed to get backlight\n");

	drm_panel_add(&ctx->panel);

	ret = mipi_dsi_attach(dsi);
	if (ret < 0) {
		drm_panel_remove(&ctx->panel);
		return dev_err_probe(dev, ret, "failed to attach DSI\n");
	}

	return 0;
}

static void ft8201e_panel_remove(struct mipi_dsi_device *dsi)
{
	struct ft8201e_panel *ctx = mipi_dsi_get_drvdata(dsi);

	mipi_dsi_detach(dsi);
	drm_panel_remove(&ctx->panel);
}

static const struct of_device_id ft8201e_panel_of_match[] = {
	{ .compatible = "tlcm,hjr104017d-a1-ft8201e" },
	{ }
};
MODULE_DEVICE_TABLE(of, ft8201e_panel_of_match);

static struct mipi_dsi_driver ft8201e_panel_driver = {
	.driver = {
		.name = "panel-ft8201e-hjr104017d-a1",
		.of_match_table = ft8201e_panel_of_match,
	},
	.probe = ft8201e_panel_probe,
	.remove = ft8201e_panel_remove,
};

module_mipi_dsi_driver(ft8201e_panel_driver);

MODULE_AUTHOR("Generated from Unisoc/Spreadtrum DTS");
MODULE_DESCRIPTION("FT8201E TLCM HJR104017D A1 MIPI DSI panel");
MODULE_LICENSE("GPL");
