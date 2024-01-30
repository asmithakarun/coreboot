/* SPDX-License-Identifier: GPL-2.0-only */

/* TO BE UPDATED */
#ifndef CFG_GPIO_H
#define CFG_GPIO_H

#include <gpio.h>

static const struct pad_config gpio_table[] = {
        /* ------- GPIO Community 0 ------- */
        /* ------- GPIO Group GPPC_A ------- */
        /* PCH default for ESPI inter GPPC_A0-A9 */
        /* Unused */
        PAD_NC(GPPC_A10, NONE),
        PAD_NC(GPPC_A11, NONE),
        PAD_NC(GPPC_A12, NONE),
        PAD_NC(GPPC_A13, NONE),
        PAD_NC(GPPC_A14, NONE),
        PAD_NC(GPPC_A16, NONE),
        PAD_NC(GPPC_A17, NONE),
        PAD_NC(GPPC_A18, NONE),
        PAD_NC(GPPC_A19, NONE),

	PAD_CFG_NF(GPPC_A15, NONE, DEEP, NF1),

        /* ------- GPIO Group GPPC_B ------- */
        /* Unused GPPC_B0-B11 */
        PAD_NC(GPPC_B0, NONE),
	PAD_NC(GPPC_B1, NONE),
        PAD_NC(GPPC_B2, NONE),
        PAD_NC(GPPC_B3, NONE),
        PAD_NC(GPPC_B4, NONE),
        PAD_NC(GPPC_B5, NONE),
        PAD_NC(GPPC_B6, NONE),
        PAD_NC(GPPC_B7, NONE),
        PAD_NC(GPPC_B8, NONE),
        PAD_NC(GPPC_B9, NONE),
        PAD_NC(GPPC_B10, NONE),
        PAD_NC(GPPC_B11, NONE),
        
        PAD_CFG_NF(GPPC_B12, NONE, DEEP, NF1),
	PAD_CFG_NF(GPPC_B13, NONE, DEEP, NF1),

	PAD_NC(GPPC_B14, NONE),
        
	PAD_CFG_NF(GPPC_B15, NONE, DEEP, NF1),

	/* Unused GPPC_B16-B23 */
	PAD_NC(GPPC_B16, NONE),
        PAD_NC(GPPC_B17, NONE),
        PAD_NC(GPPC_B18, NONE),
        PAD_NC(GPPC_B19, NONE),
        PAD_NC(GPPC_B20, NONE),
        PAD_NC(GPPC_B21, NONE),
        PAD_NC(GPPC_B22, NONE),
        PAD_NC(GPPC_B23, NONE),

        /* ------- GPIO Community 1 ------- */
        /* ------- GPIO Group GPPC_C ------- */
        /* ME_SML0CLK */
        PAD_CFG_NF(GPPC_C0, NONE, DEEP, NF1),
        PAD_CFG_NF(GPPC_C1, NONE, DEEP, NF1),
        PAD_CFG_NF(GPPC_C2, NONE, DEEP, NF1),

        /* FM_BIOS_POST_CMPLT_N */
	PAD_CFG_NF(GPPC_C6, NONE, DEEP, NF1),
        PAD_CFG_NF(GPPC_C7, NONE, DEEP, NF1),
        PAD_CFG_NF(GPPC_C8, NONE, DEEP, NF1),
        PAD_CFG_NF(GPPC_C9, NONE, DEEP, NF1),
        PAD_CFG_NF(GPPC_C10, NONE, DEEP, NF1),
        PAD_CFG_NF(GPPC_C11, NONE, DEEP, NF1),
        PAD_CFG_NF(GPPC_C14, NONE, DEEP, NF1),
        PAD_CFG_NF(GPPC_C17, NONE, DEEP, NF1),

        /* No Connect */
        PAD_NC(GPPC_C3, NONE),
        PAD_NC(GPPC_C4, NONE),
        PAD_NC(GPPC_C5, NONE),
        PAD_NC(GPPC_C12, NONE),
        PAD_NC(GPPC_C13, NONE),
        PAD_NC(GPPC_C15, NONE),
        PAD_NC(GPPC_C16, NONE),
        PAD_NC(GPPC_C18, NONE),
        PAD_NC(GPPC_C19, NONE),
        PAD_NC(GPPC_C20, NONE),
        PAD_NC(GPPC_C21, NONE),

        /* ------- GPIO Group GPPC_S ------- */
        PAD_CFG_NF(GPPC_S0, NONE, DEEP, NF1),
	//PAD_CFG_NF(GPPC_S1, NONE, DEEP, NF2),
	PAD_CFG_NF(GPPC_S1, DN_20K, DEEP, NF2),
        PAD_CFG_NF(GPPC_S2, NONE, DEEP, NF1),
        PAD_CFG_NF(GPPC_S3, NONE, DEEP, NF1),
        PAD_CFG_NF(GPPC_S4, NONE, DEEP, NF1),
        PAD_CFG_NF(GPPC_S5, NONE, DEEP, NF1),
        PAD_CFG_NF(GPPC_S6, NONE, DEEP, NF1),
        PAD_CFG_NF(GPPC_S7, NONE, DEEP, NF1),
        PAD_CFG_NF(GPPC_S8, NONE, DEEP, NF1),
        PAD_CFG_NF(GPPC_S9, NONE, DEEP, NF1),
        PAD_CFG_NF(GPPC_S10, NONE, DEEP, NF1),
        PAD_CFG_NF(GPPC_S11, NONE, DEEP, NF1),

        /* FM_SMI_ACTIVE_N */
        PAD_CFG_NF(GPPC_S9, NONE, DEEP, NF1),

        /* ------- GPIO Group GPP_D ------- */
        /* SMB_HOST_STBY_BMC_LVC3_R2 */
        PAD_CFG_NF(GPP_D8, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_D11, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_D12, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_D13, DN_20K, DEEP, NF1),
        PAD_CFG_NF(GPP_D14, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_D16, DN_20K, DEEP, NF1),
        PAD_CFG_NF(GPP_D17, NONE, DEEP, NF1),
        PAD_CFG_NF(GPP_D18, NONE, DEEP, NF1),
        PAD_CFG_NF(GPP_D19, NONE, DEEP, NF1),
        PAD_CFG_NF(GPP_D21, NONE, DEEP, NF1),

        /* No Connect */
	PAD_NC(GPP_D0, NONE),
        PAD_NC(GPP_D1, NONE),
        PAD_NC(GPP_D2, NONE),
	PAD_NC(GPP_D6, NONE),
	PAD_NC(GPP_D7, DN_20K),
        PAD_NC(GPP_D9, NONE),
        PAD_NC(GPP_D10, NONE),
        PAD_NC(GPP_D15, NONE),
        PAD_NC(GPP_D20, NONE),
        PAD_NC(GPP_D22, NONE),
        PAD_NC(GPP_D23, DN_20K),

        /* ------- GPIO Community 2 ------- */
        /* ------- GPIO Group GPP_O ------- */
        /* Unused */
        PAD_NC(GPP_O0, NONE),
        PAD_NC(GPP_O7, NONE),

        /* ------- GPIO Community 3 ------- */
        /* ------- GPIO Group GPP_E ------- */
	PAD_CFG_NF(GPP_E0, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_E1, NONE, DEEP, NF1),
        PAD_CFG_NF(GPP_E2, NONE, DEEP, NF1),
        PAD_CFG_NF(GPP_E3, NONE, DEEP, NF1),
        PAD_CFG_NF(GPP_E4, NONE, DEEP, NF1),
        PAD_CFG_NF(GPP_E5, NONE, DEEP, NF1),
        PAD_CFG_NF(GPP_E9, NONE, DEEP, NF1),
        PAD_CFG_NF(GPP_E13, NONE, DEEP, NF2), // Recheck
        PAD_CFG_GPI(GPP_E15, NONE, DEEP, NF1), // Recheck
        PAD_CFG_GPI(GPP_E16, NONE, DEEP, NF1), // Recheck

        /* Unused */
        PAD_NC(GPP_E6, NONE),
        PAD_NC(GPP_E7, NONE),
        PAD_NC(GPP_E8, NONE),
        PAD_NC(GPP_E10, NONE),
        PAD_NC(GPP_E11, NONE),
        PAD_NC(GPP_E12, NONE),
        PAD_NC(GPP_E14, NONE),
        PAD_NC(GPP_E17, NONE),
        PAD_NC(GPP_E18, NONE),
        PAD_NC(GPP_E19, NONE),

        /* ------- GPIO Community 4 ------- */
        /* -------- GPIO Group GPPC_H -------- */
        /* Unused */
        PAD_NC(GPPC_H0, DN_20K),
        PAD_NC(GPPC_H1, NONE),
        PAD_NC(GPPC_H6, DN_20K),
        PAD_NC(GPPC_H7, NONE),
        PAD_NC(GPPC_H15, NONE),
        PAD_NC(GPPC_H18, NONE),
        PAD_NC(GPPC_H19, NONE),

        PAD_CFG_NF(GPPC_H16, NONE, DEEP, NF2),
	PAD_CFG_NF(GPPC_H17, NONE, DEEP, NF2),

        /* ------- GPIO Group GPP_J ------- */
        /* Use PCH defaults */
        /* GPP_J0 CPUPWRGD */
        /* GPP_J1 CPU_THRMTRIP_N */
        /* GPP_J2 PLTRST_CPU_N */
        /* GPP_J3 TRIGGER0_N */
        /* GPP_J4 TRIGGER1_N */
        /* GPP_J5 CPU_PWER_DEBUG_N */
        /* GPP_J6 CPU_MEMTRIP_N */
        /* GPP_J7 CPU_MSMI_N */
        /* GPP_J12 CPU_ERR0_N */
        /* GPP_J13 CPU_CATERR_N */
        /* GPP_J14 CPU_ERR1_N */
        /* GPP_J15 CPU_ERR2_N */

        /* ------- GPIO Community 5 ------- */
        /* ------- GPIO Group GPP_I ------- */
        /* Unused */
        PAD_NC(GPP_I12, NONE),
        PAD_NC(GPP_I13, NONE),
        PAD_NC(GPP_I14, NONE),
        PAD_NC(GPP_I15, NONE),
        PAD_NC(GPP_I16, NONE),
        PAD_NC(GPP_I17, NONE),
        PAD_NC(GPP_I21, NONE),
	PAD_NC(GPP_I22, NONE),
        PAD_NC(GPP_I23, NONE),

        /* ------- GPIO Group GPP_L ------- */
        /* Chip default */
        /* GPP_L_0 PM_SYNC_0 */
        /* GPP_L_1 PM_DOWN_0 */

        /* Unused */
        PAD_NC(GPP_L2, NONE),
        PAD_NC(GPP_L3, NONE),
        PAD_NC(GPP_L4, NONE),
	PAD_NC(GPP_L5, NONE),
        PAD_NC(GPP_L6, NONE),
        PAD_NC(GPP_L7, NONE),
        PAD_NC(GPP_L8, NONE),

        /* ------- GPIO Group GPP_M ------- */
        /* Unused */
        PAD_NC(GPP_M0, NONE),
        PAD_NC(GPP_M1, NONE),
        PAD_NC(GPP_M2, NONE),
        PAD_NC(GPP_M3, NONE),
        PAD_NC(GPP_M4, NONE),
        PAD_NC(GPP_M5, NONE),
        PAD_NC(GPP_M6, NONE),
        PAD_NC(GPP_M7, NONE),
        PAD_NC(GPP_M8, NONE),
        PAD_NC(GPP_M11, DN_20K),
        PAD_NC(GPP_M12, NONE),
        PAD_NC(GPP_M15, NONE),
        PAD_NC(GPP_M16, NONE),
        PAD_NC(GPP_M17, NONE),

        /* ------- GPIO Group GPP_N ------- */
        /* Unused */
        PAD_NC(GPP_N1, NONE),
        PAD_NC(GPP_N4, NONE),
};

#endif /* CFG_GPIO_H */
