/* SPDX-License-Identifier: GPL-2.0-only */

#include <console/console.h>
#include <soc/romstage.h>
#include <soc/ddr.h>
#include <soc/soc_util.h>
#include <defs_cxl.h>
#include <hob_iiouds.h>

/* For now only set 3 fields and hard-coded others, should be extended in the future */
#define CFG_UPD_PCIE_PORT(pexphide, slotimp, slotpsp)   \
        {                                               \
                .SLOTEIP = 0,                           \
                .SLOTHPCAP = slotimp,                   \
                .SLOTHPSUP = slotimp,                   \
                .SLOTPIP = 0,                           \
                .SLOTAIP = 0,                           \
                .SLOTMRLSP = 0,                         \
                .SLOTPCP = 0,                           \
                .SLOTABP = 0,                           \
                .SLOTIMP = slotimp,                     \
                .SLOTSPLS = 0,                          \
                .SLOTSPLV = slotimp ? 25 : 0,           \
                .SLOTPSP = slotpsp,                     \
                .VppEnabled = 0,                        \
                .VppPort = 0,                           \
                .VppAddress = 0,                        \
                .MuxAddress = 0,                        \
                .ChannelID = 0,                         \
                .PciePortEnable = !pexphide,            \
                .PEXPHIDE = pexphide,                   \
                .HidePEXPMenu = pexphide,               \
                .PciePortOwnership = 0,                 \
                .RetimerConnectCount = 0,               \
                .PcieMaxPayload = 0x7,                  \
                .PcieHotPlugOnPort = slotimp,           \
        }


static const UPD_IIO_PCIE_PORT_CONFIG_ENTRY
system1_socket_config[CONFIG_MAX_SOCKET][IIO_PORT_SETTINGS] = {
        {
	/* DMI port: array index 0 */
        CFG_UPD_PCIE_PORT(0, 0, 0),
        /* IOU0 (PE0): array index 1 ~ 8 */
        CFG_UPD_PCIE_PORT(0, 1, 1), /* NIC1 */
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        /* IOU1 (PE1): array index 9 ~ 16 */
        CFG_UPD_PCIE_PORT(0, 1, 9), /* SW1 STK5 */
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        /* IOU2 (PE2): array index 17 ~ 24 */
        CFG_UPD_PCIE_PORT(0, 1, 17), /* SW1 STK4 */
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        /* IOU3 (PE3): array index 33 ~ 40 */
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        /* IOU4 (PE4): array index 33 ~ 40 */
        CFG_UPD_PCIE_PORT(0, 1, 33), /* U.2-2 */
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(0, 1, 35), /* U.2-0 */
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        /* System1 doesn't use IOU5 ~ IOU6. */
        },
        {
        /* DMI port: array index 0 */
        CFG_UPD_PCIE_PORT(1, 0, 0),
        /* IOU0 (PE0): array index 1 ~ 8 */
        CFG_UPD_PCIE_PORT(0, 1, 1), /* SW2 STK5 */
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        /* IOU1 (PE1): array index 9 ~ 16 */
        CFG_UPD_PCIE_PORT(0, 1, 9), /* SW2 STK4 */
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        /* IOU2 (PE2): array index 17 ~ 24 */
        CFG_UPD_PCIE_PORT(0, 1, 17), /* NIC2 */
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        /* IOU3 (PE3): array index 25 ~ 32 */
        CFG_UPD_PCIE_PORT(0, 1, 25), /* U.2-2 */
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(0, 1, 27), /* U.2-0 */
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        /* IOU4 (PE4): array index 33 ~ 40 */
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        CFG_UPD_PCIE_PORT(1, 0, 0),
        /* System1 doesn't use IOU5 ~ IOU6. */
        },
};

static const UINT8 system1_socket_config_iou[CONFIG_MAX_SOCKET][5] = {
        {
                IIO_BIFURCATE_xxxxxx16,
		IIO_BIFURCATE_xxxxxx16,
		IIO_BIFURCATE_xxxxxx16,
		IIO_BIFURCATE_xxxxxxxx,
		IIO_BIFURCATE_x4x4x4x4,
        },
        {
                IIO_BIFURCATE_xxxxxx16,
                IIO_BIFURCATE_xxxxxx16,
                IIO_BIFURCATE_xxxxxx16,
                IIO_BIFURCATE_x4x4x4x4,
                IIO_BIFURCATE_xxxxxxxx,
        },
};

void mainboard_memory_init_params(FSPM_UPD *mupd)
{
        UINT32 *sktbmp;

        /* Set Rank Margin Tool to disable. */
        mupd->FspmConfig.EnableRMT = 0x0;

        /* Set Promote Warnings to disable. */
        /* Determines if warnings are promoted to system level. */
        mupd->FspmConfig.promoteWarnings = 0x0;

        /* Set FSP debug message to Disable */
        mupd->FspmConfig.serialDebugMsgLvl = 0x0;

        /* Force 256MiB MMCONF (Segment0) only */
        mupd->FspmConfig.mmCfgSize = 0x2;
        mupd->FspmConfig.PcieHotPlugEnable = 0;

        /*
         * Disable unused IIO stack:
         * Socket 0 : IIO2
         * Socket 1 : IIO4
         * Stack Disable bit mapping is:
         * IIO stack number:  1 2 3 4 5
         * Stack Disable Bit: 1 5 3 2 4
         */
        sktbmp = (UINT32 *)&mupd->FspmConfig.StackDisableBitMap[0];
        sktbmp[0] = BIT(5);
        sktbmp[1] = BIT(2);
        soc_config_iio(mupd, system1_socket_config, system1_socket_config_iou);
}

bool mainboard_dimm_slot_exists(uint8_t socket, uint8_t channel, uint8_t dimm)
{
        if (socket >= CONFIG_MAX_SOCKET)
                return false;
        if (channel >= 8)
                return false;
        if (dimm >= 2)
                return false;

        return true;
}
