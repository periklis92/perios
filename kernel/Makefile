KERNEL_ROOT=kernel

KERNEL_CFLAGS=$(CFLAGS) --sysroot=$(PWD)/sysroot -isystem=$(INCLUDEDIR) -Iinclude
KERNEL_LDFLAGS:=$(LDFLAGS) -nostdlib $(DESTDIR)/$(LIBDIR)/libk.a

KERNEL_ARCHDIR:=$(KERNEL_ROOT)/arch/$(ARCH)

include $(KERNEL_ARCHDIR)/make.config
include $(KERNEL_ROOT)/drivers/make.config
include $(KERNEL_ROOT)/kernel/make.config

KERNEL_CFLAGS:=$(KERNEL_CFLAGS) $(KERNEL_ARCH_FLAGS)
KERNEL_LDFLAGS:=$(KERNEL_LDFLAGS) $(KERNEL_ARCH_LDFLAGS)

KERNEL_OBJS:=\
$(KERNEL_ARCH_OBJS_PRE)\
$(KERNEL_ARCH_OBJS) \

KERNEL_CRTI_OBJ:=$(KERNEL_ARCHDIR)/crti.o
KERNEL_CRTBEGIN_OBJ:=$(shell $(CC) $(KERNEL_CFLAGS) $(KERNEL_LDFLAGS) -print-file-name=crtbegin.o)
KERNEL_CRTEND_OBJ:=$(shell $(CC) $(KERNEL_CFLAGS) $(KERNEL_LDFLAGS) -print-file-name=crtend.o)
KERNEL_CRTN_OBJ:=$(KERNEL_ARCHDIR)/crtn.o

KERNEL_ALL_OBJS:=\
$(KERNEL_CRTI_OBJ)\
$(KERNEL_OBJS)\
$(KERNEL_CRTN_OBJ)\

KERNEL_OBJ_LINK_LIST:=\
$(KERNEL_CRTI_OBJ)\
$(KERNEL_CRTBEGIN_OBJ)\
$(KERNEL_OBJS)\
$(KERNEL_CRTEND_OBJ)\
$(KERNEL_CRTN_OBJ)\

.PHONY: kernel_clean kernel_install kernel_install_headers kernel_install_binaries


perios.kernel: $(KERNEL_OBJ_LINK_LIST) $(KERNEL_ARCHDIR)/linker.ld
	$(CC) -T $(KERNEL_ARCHDIR)/linker.ld -o $(KERNEL_ROOT)/$@ $(KERNEL_FLAGS) \
	$(KERNEL_OBJ_LINK_LIST) $(KERNEL_LDFLAGS) $(LIBS)

%.o: %.c
	$(CC) -c $< -o $@ $(KERNEL_CFLAGS)

%.o: %.asm
	$(AS) -felf32 $< -o $@

kernel_clean:
	rm -f perios.kernel $(KERNEL_OBJS) $(KERNEL_ALL_OBJS) *.o */*.o */*/*.o

kernel_install: kernel_install_headers kernel_install_binaries

kernel_install_headers:
	mkdir -p $(DESTDIR)/$(INCLUDEDIR)
	cp -Rv $(KERNEL_ROOT)/include/* $(DESTDIR)/$(INCLUDEDIR)/

kernel_install_binaries: perios.kernel
	mkdir -p $(DESTDIR)/$(BOOTDIR)
	cp -Rv $(KERNEL_ROOT)/perios.kernel $(DESTDIR)/$(BOOTDIR)/




