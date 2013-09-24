/*
 *  Copyright (C) 2012-2013 Samsung Electronics Co., Ltd.
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef _EXFAT_GLOBAL_H
#define _EXFAT_GLOBAL_H

#include <linux/kernel.h>
#include <linux/mm.h>
#include <linux/slab.h>
#include <linux/string.h>
#include <linux/fs.h>


#ifdef __cplusplus
extern "C" {
#endif

s32 __wstrchr(u16 *str, u16 wchar);

#define WSTRCHR(str, wchar)             __wstrchr(str, wchar)

#ifdef CONFIG_EXFAT_DEBUG_MSG
#define PRINTK(...)			\
	do {								\
		printk("[EXFAT] " __VA_ARGS__);	\
	} while(0)
#else
#define PRINTK(...)
#endif

	void    Bitmap_set_all(u8 *bitmap, s32 mapsize);
	void    Bitmap_clear_all(u8 *bitmap, s32 mapsize);
	s32   Bitmap_test(u8 *bitmap, s32 i);
	void    Bitmap_set(u8 *bitmap, s32 i);
	void    Bitmap_clear(u8 *bitmpa, s32 i);
	void    Bitmap_nbits_set(u8 *bitmap, s32 offset, s32 nbits);
	void    Bitmap_nbits_clear(u8 *bitmap, s32 offset, s32 nbits);

	void    my_itoa(char *buf, s32 v);

#ifdef PRINT
#undef PRINT
#endif

#define PRINT                   printk
#ifdef __cplusplus
}
#endif
#endif
