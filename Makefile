HOST=i686-elf
ARCH=x86

CC=$(HOST)-gcc
AR=$(HOST)-ar
AS=nasm

CFLAGS= -ffreestanding -O2 -nostdlib -Wall -g -D__isperios_kernel
LDFLAGS?=

DESTDIR?=sysroot/
PREFIX=/usr
EXEC_PREFIX=$(PREFIX)
INCLUDEDIR=$(PREFIX)/include
LIBDIR=$(EXEC_PREFIX)/lib
BOOTDIR=/boot
PWD:=$(shell pwd)

TARGET_ISO=perios.iso

MKRESCUE:=$(shell command -v grub-mkrescue 2>/dev/null || command -v grub-mkrescue 2>/dev/null)
XORRISO:=$(shell command -v xorriso 2>/dev/null)

include kernel/Makefile
include libk/Makefile

.PHONY:clean build iso

all: clean_all build iso qemu

clean_all: clean
	rm -rf perios.iso
	rm -rfv sysroot

clean: kernel_clean
	rm -rfv isodir

build: install_headers install_libs install_binaries

iso: build
	mkdir -p isodir/boot/grub
	@echo "menuentry \"PeriOS\" {\n \
	\tmultiboot /boot/perios.kernel\n \
	}" > isodir/boot/grub/grub.cfg
	cp $(DESTDIR)/$(BOOTDIR)/perios.kernel isodir/boot/perios.kernel
	$(MKRESCUE) -o $(TARGET_ISO) isodir

qemu: iso
	qemu-system-i386 -cdrom $(TARGET_ISO)


install_headers: libk_install_headers kernel_install_headers
install_libs: libk_install_libs
install_binaries: kernel_install_binaries
