/*******************************************************************
 * Copyright 2021-2080 evilbinary
 * 作者: evilbinary on 01/01/20
 * 邮箱: rootdebug@163.com
 ********************************************************************/
#ifndef DEVICE_H
#define DEVICE_H

#include "arch/arch.h"


enum {
    DEVICE_KEYBOARD=0,
    DEVICE_PCI,
    DEVICE_VGA,
};

enum {
    DEVICE_TYPE_CHAR=1,
    DEVICE_TYPE_BLOCK,
    DEVICE_TYPE_VIRTUAL,
    DEVICE_TYPE_VGA,
    DEVICE_TYPE_NET
};

#define MAX_DEVICE 256


typedef struct fd{
    u32 id;
    u32 type; // file ,socket, pipe dir
}fd_t;

typedef struct stat {
	size_t size;
	int is_dir;
}stat_t;

typedef struct device device_t;

typedef size_t (*dev_read_fn)(device_t* fd, void *buf, size_t len);
typedef size_t (*dev_write_fn)(device_t* fd, const void *buf, size_t len);
typedef int (*dev_stat_fn)(device_t * fd, stat_t *stat);

typedef struct device{
    char* name;
    u32 id;
    u32 type; //char block vga
	dev_read_fn read;
    dev_write_fn write;
    dev_stat_fn stat;
    void* data; //data
}device_t;

void device_add(device_t* device);

void device_remove();

device_t* device_find(u32 id);


#endif