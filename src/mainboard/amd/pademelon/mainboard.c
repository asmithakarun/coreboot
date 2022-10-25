/* SPDX-License-Identifier: GPL-2.0-only */

#include <device/device.h>
#include <amdblocks/agesawrapper.h>
#include <amdblocks/amd_pci_util.h>
#include <soc/gpio.h>
#include <soc/pci_devs.h>
#include <soc/southbridge.h>

#include "gpio.h"

/***********************************************************
 * These arrays set up the FCH PCI_INTR registers 0xC00/0xC01.
 * This table is responsible for physically routing the PIC and
 * IOAPIC IRQs to the different PCI devices on the system.  It
 * is read and written via registers 0xC00/0xC01 as an
 * Index/Data pair.  These values are chipset and mainboard
 * dependent and should be updated accordingly.
 *
 * These values are used by the PCI configuration space,
 * MP Tables.
 */
static const u8 mainboard_picr_data[FCH_IRQ_ROUTING_ENTRIES] = {
	[0x00] = 0x03, 0x04, 0x05, 0x07, 0x0B, 0x0A, 0x1F, 0x1F,
	[0x08] = 0xFA, 0xF1, 0x00, 0x00, 0x1F, 0x1F, 0x1F, 0x1F,
	[0x10] = 0x1F, 0x1F, 0x1F, 0x03, 0x1F, 0x1F, 0x1F, 0x1F,
	[0x18] = 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	[0x20] = 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x00, 0x00,
	[0x28] = 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	[0x30] = 0x05, 0x04, 0x05, 0x04, 0x04, 0x05, 0x04, 0x05,
	[0x38] = 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	[0x40] = 0x04, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	[0x48] = 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	[0x50] = 0x03, 0x04, 0x05, 0x07, 0x1F, 0x1F, 0x1F, 0x1F,
	[0x58] = 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F,
	[0x60] = 0x1F, 0x1F, 0x07, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F,
	[0x68] = 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F,
	[0x70] = 0x03, 0x0F, 0x06, 0x0E, 0x0A, 0x0B, 0x1F, 0x1F,
	[0x78] = 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F,
};

static const u8 mainboard_intr_data[FCH_IRQ_ROUTING_ENTRIES] = {
	[0x00] = 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
	[0x08] = 0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F, 0x1F, 0x1F,
	[0x10] = 0x09, 0x1F, 0x1F, 0x10, 0x1F, 0x1F, 0x1F, 0x10,
	[0x18] = 0x1F, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00,
	[0x20] = 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x00, 0x00,
	[0x28] = 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	[0x30] = 0x12, 0x11, 0x12, 0x11, 0x12, 0x11, 0x12, 0x00,
	[0x38] = 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	[0x40] = 0x11, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	[0x48] = 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	[0x50] = 0x1F, 0x1F, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00,
	[0x58] = 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	[0x60] = 0x1F, 0x1F, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
	[0x68] = 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	[0x70] = 0x03, 0x0F, 0x06, 0x0E, 0x0A, 0x0B, 0x1F, 0x1F,
	[0x78] = 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

/*
 * This table defines the index into the picr/intr_data tables for each
 * device.  Any enabled device and slot that uses hardware interrupts should
 * have an entry in this table to define its index into the FCH PCI_INTR
 * register 0xC00/0xC01.  This index will define the interrupt that it should
 *  use. Putting PIRQ_A into the PIN A index for a device will tell that
 * device to use PIC IRQ 10 if it uses PIN A for its hardware INT.
 */
static const struct pirq_struct mainboard_pirq_data[] = {
	{ GFX_DEVFN,	{ PIRQ_A, PIRQ_NC, PIRQ_NC, PIRQ_NC } },
	{ HDA0_DEVFN,	{ PIRQ_NC, PIRQ_HDA, PIRQ_NC, PIRQ_NC } },
	{ PCIE0_DEVFN,	{ PIRQ_A, PIRQ_B, PIRQ_C, PIRQ_D } },
	{ PCIE1_DEVFN,	{ PIRQ_B, PIRQ_C, PIRQ_D, PIRQ_A } },
	{ PCIE2_DEVFN,	{ PIRQ_C, PIRQ_D, PIRQ_A, PIRQ_B } },
	{ PCIE3_DEVFN,	{ PIRQ_D, PIRQ_A, PIRQ_B, PIRQ_C } },
	{ PCIE4_DEVFN,	{ PIRQ_A, PIRQ_B, PIRQ_C, PIRQ_D } },
	{ PSP_DEVFN,	{ PIRQ_A, PIRQ_NC, PIRQ_NC, PIRQ_NC } },
	{ HDA1_DEVFN,	{ PIRQ_HDA, PIRQ_NC, PIRQ_NC, PIRQ_NC } },
	{ SD_DEVFN,	{ PIRQ_SD, PIRQ_NC, PIRQ_NC, PIRQ_NC } },
	{ SMBUS_DEVFN,	{ PIRQ_SMBUS, PIRQ_NC, PIRQ_NC, PIRQ_NC } },
	{ SATA_DEVFN,	{ PIRQ_SATA, PIRQ_NC, PIRQ_NC, PIRQ_NC } },
	{ EHCI1_DEVFN,	{ PIRQ_EHCI, PIRQ_NC, PIRQ_NC, PIRQ_NC } },
	{ XHCI_DEVFN,	{ PIRQ_XHCI, PIRQ_NC, PIRQ_NC, PIRQ_NC } },
};

/* PIRQ Setup */
static void pirq_setup(void)
{
	pirq_data_ptr = mainboard_pirq_data;
	pirq_data_size = ARRAY_SIZE(mainboard_pirq_data);
	intr_data_ptr = mainboard_intr_data;
	picr_data_ptr = mainboard_picr_data;
}

static void mainboard_init(void *chip_info)
{
	size_t num_gpios;
	const struct soc_amd_gpio *gpios;
	gpios = gpio_table(&num_gpios);
	gpio_configure_pads(gpios, num_gpios);
}

/*************************************************
 * enable the dedicated function in pademelon board.
 *************************************************/
static void mainboard_enable(struct device *dev)
{
	/* Initialize the PIRQ data structures for consumption */
	pirq_setup();
}

struct chip_operations mainboard_ops = {
	.init = mainboard_init,
	.enable_dev = mainboard_enable,
};
