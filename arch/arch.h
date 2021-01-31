/*******************************************************************
* Copyright 2021-2080 evilbinary
* 作者: evilbinary on 01/01/20
* 邮箱: rootdebug@163.com
********************************************************************/
#ifndef ARCH_H
#define ARCH_H

#include "libs/include/types.h"
#include "boot.h"
#include "cpu.h"
#include "display.h"
#include "mm.h"
#include "common.h"
#include "interrupt.h"
#include "lock.h"

void arch_init(boot_info_t* boot_info);

#endif