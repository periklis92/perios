#ifndef KERNEL_H
#define KERNEL_H 1

#include <kernel/multiboot.h>
#include <stdio.h>
#include <sys/tty.h>
#include <sys/cdefs.h>

void mboot(uint32_t, multiboot_info_t*);
void kmain(void);

#endif
