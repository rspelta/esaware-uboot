/*
 * TI PHY drivers
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 *
 * Base code from drivers/net/phy/davicom.c
 *   Copyright 2010-2011 Freescale Semiconductor, Inc.
 *   author Andy Fleming
 *
 * Some code get from linux kenrel
 * Copyright (c) 2006 Herbert Valerio Riedel <hvr@gnu.org>
 *
 */
#include <miiphy.h>

static int ti_parse_status(struct phy_device *phydev)
{
	int mii_reg;

	mii_reg = phy_read(phydev, MDIO_DEVAD_NONE, MII_BMSR);

	if (mii_reg & (BMSR_100FULL | BMSR_100HALF))
		phydev->speed = SPEED_100;
	else
		phydev->speed = SPEED_10;

	if (mii_reg & (BMSR_10FULL | BMSR_100FULL))
		phydev->duplex = DUPLEX_FULL;
	else
		phydev->duplex = DUPLEX_HALF;

	return 0;
}

static int ti_startup(struct phy_device *phydev)
{
//printf("ti_startup\n");
	genphy_update_link(phydev);
	ti_parse_status(phydev);
	return 0;
}

static struct phy_driver dp83848_driver = {
	.name = "TI DP83848",
	.uid = 0x20005c90,//0x0007c0c0,
	.mask = 0x2000FF90,//0xffff0,
	.features = PHY_BASIC_FEATURES,
	.config = &genphy_config_aneg,
	.startup = &ti_startup,
	.shutdown = &genphy_shutdown,
};

int phy_ti_init(void)
{
	phy_register(&dp83848_driver);

	return 0;
}
