/*
 * drivers/video/tegra/dc/hdmihdcp.h
 *
 * Copyright (c) 2014, NVIDIA CORPORATION, All rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef __DRIVERS_VIDEO_TEGRA_DC_HDMIHDCP_H
#define __DRIVERS_VIDEO_TEGRA_DC_HDMIHDCP_H
#include <video/nvhdcp.h>

#define HDCP_HDCP2_VERSION		0x50
#define HDCP_HDCP2_VERSION_HDCP22_YES	0x04
#define HDCP_HDCP2_VERSION_HDCP22_NO	0x00

#define HDCP_WRITE_MSG			0x60

#define HDCP_RX_STATUS			0x70
#define HDCP_RX_STATUS_MSG_SIZE_MASK	0x03ff
#define HDCP_RX_STATUS_MSG_READY_YES	0x0400
#define HDCP_RX_STATUS_MSG_READY_NO	0x0000
#define HDCP_RX_STATUS_MSG_REAUTH_REQ	0x0800

#define HDCP_READ_MSG			0x80

struct tegra_nvhdcp;
#ifdef CONFIG_TEGRA_HDMIHDCP
void tegra_nvhdcp_set_plug(struct tegra_nvhdcp *nvhdcp, bool hpd);
int tegra_nvhdcp_set_policy(struct tegra_nvhdcp *nvhdcp, int pol);
void tegra_nvhdcp_suspend(struct tegra_nvhdcp *nvhdcp);
void tegra_nvhdcp_resume(struct tegra_nvhdcp *nvhdcp);
struct tegra_nvhdcp *tegra_nvhdcp_create(struct tegra_hdmi *hdmi,
					int id, int bus);
void tegra_nvhdcp_destroy(struct tegra_nvhdcp *nvhdcp);
#else
static inline void tegra_nvhdcp_set_plug(struct tegra_nvhdcp *nvhdcp, bool hpd)
{
}
static inline int tegra_nvhdcp_set_policy(struct tegra_nvhdcp *nvhdcp, int pol)
{
	return 0;
}
static inline void tegra_nvhdcp_suspend(struct tegra_nvhdcp *nvhdcp) { }
static inline void tegra_nvhdcp_resume(struct tegra_nvhdcp *nvhdcp) { }
static inline struct tegra_nvhdcp *tegra_nvhdcp_create(
	struct tegra_hdmi *hdmi, int id, int bus)
{
	return NULL;
}
static inline void tegra_nvhdcp_destroy(struct tegra_nvhdcp *nvhdcp) { }
#endif

#endif