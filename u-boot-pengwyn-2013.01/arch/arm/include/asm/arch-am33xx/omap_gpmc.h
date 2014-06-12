/*
 * (C) Copyright 2004-2008 Texas Instruments, <www.ti.com>
 * Rohit Choraria <rohitkc@ti.com>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
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
 */
#ifndef __ASM_ARCH_OMAP_GPMC_H
#define __ASM_ARCH_OMAP_GPMC_H

#define GPMC_BUF_EMPTY	0
#define GPMC_BUF_FULL	1

#define ECCCLEAR	(0x1 << 8)
#define ECCRESULTREG1	(0x1 << 0)
#define ECCSIZE512BYTE	0xFF
#define ECCSIZE1	(ECCSIZE512BYTE << 22)
#define ECCSIZE0	(ECCSIZE512BYTE << 12)
#define ECCSIZE0SEL	(0x000 << 0)

/* Generic ECC Layouts */
/* Large Page x8 NAND device Layout */
#ifdef GPMC_NAND_ECC_LP_x8_LAYOUT
#define GPMC_NAND_HW_ECC_LAYOUT {\
	.eccbytes = 12,\
	.eccpos = {1, 2, 3, 4, 5, 6, 7, 8,\
		9, 10, 11, 12},\
	.oobfree = {\
		{.offset = 13,\
		 .length = 51 } } \
}
#endif

/* Large Page x16 NAND device Layout */
#ifdef GPMC_NAND_ECC_LP_x16_LAYOUT
#define GPMC_NAND_HW_ECC_LAYOUT {\
	.eccbytes = 12,\
	.eccpos = {2, 3, 4, 5, 6, 7, 8, 9,\
		10, 11, 12, 13},\
	.oobfree = {\
		{.offset = 14,\
		 .length = 50 } } \
}
#endif

/* Small Page x8 NAND device Layout */
#ifdef GPMC_NAND_ECC_SP_x8_LAYOUT
#define GPMC_NAND_HW_ECC_LAYOUT {\
	.eccbytes = 3,\
	.eccpos = {1, 2, 3},\
	.oobfree = {\
		{.offset = 4,\
		 .length = 12 } } \
}
#endif

/* Small Page x16 NAND device Layout */
#ifdef GPMC_NAND_ECC_SP_x16_LAYOUT
#define GPMC_NAND_HW_ECC_LAYOUT {\
	.eccbytes = 3,\
	.eccpos = {2, 3, 4},\
	.oobfree = {\
		{.offset = 5,\
		 .length = 11 } } \
}
#endif

#define GPMC_NAND_HW_BCH4_ECC_LAYOUT {\
	.eccbytes = 32,\
	.eccpos = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,\
				16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27,\
				28, 29, 30, 31, 32, 33},\
	.oobfree = {\
		{.offset = 34,\
		 .length = 30 } } \
}

#define GPMC_NAND_HW_BCH8_ECC_LAYOUT {\
	.eccbytes = 56,\
	.eccpos = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,\
				16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27,\
				28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39,\
				40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51,\
				52, 53, 54, 55, 56, 57},\
	.oobfree = {\
		{.offset = 58,\
		 .length = 6 } } \
}

#define GPMC_NAND_HW_BCH16_ECC_LAYOUT {\
	.eccbytes = 104,\
	.eccpos = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,\
				16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27,\
				28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39,\
				40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51,\
				52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,\
				64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75,\
				76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87,\
				88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99,\
				100, 101, 102, 103, 104, 105},\
	.oobfree = {\
		{.offset = 106,\
		 .length = 8 } } \
}

#define GPMC_1G_NAND_HW_BCH8_ECC_LAYOUT {\
	.eccbytes = 112,\
	.eccpos = {  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,	16, 17,\
				18, 19, 20, 21, 22, 23, 24, 25, 26, 27,	28, 29, 30, 31, 32, 33,\
				34, 35, 36, 37, 38, 39,	40, 41, 42, 43, 44, 45, 46, 47, 48, 49,\
				50, 51,	52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62,	63, 64, 65,\
				66, 67, 68, 69, 70, 71, 72, 73, 74,	75, 76, 77, 78, 79, 80, 81,\
				82, 83, 84, 85, 86,	87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97,\
				98,	99,100,101,102,103,104,105,106,107,108,109,110,111,112,113},\
	.oobfree = {\
		{.offset = 114,\
		 .length = 110 } } \
}

#define GPMC_1G_NAND_HW_BCH16_ECC_LAYOUT {\
	.eccbytes = 208,\
	.eccpos = {  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,	16, 17,\
				18, 19, 20, 21, 22, 23, 24, 25, 26, 27,	28, 29, 30, 31, 32, 33,\
				34, 35, 36, 37, 38, 39,	40, 41, 42, 43, 44, 45, 46, 47, 48, 49,\
				50, 51,	52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62,	63, 64, 65,\
				66, 67, 68, 69, 70, 71, 72, 73, 74,	75, 76, 77, 78, 79, 80, 81,\
				82, 83, 84, 85, 86,	87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97,\
				98,	99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,\
				114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,\
				134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,\
				154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,\
				174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,\
				194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209},\
	.oobfree = {\
		{.offset = 210,\
		 .length = 14 } } \
}

#endif /* __ASM_ARCH_OMAP_GPMC_H */

