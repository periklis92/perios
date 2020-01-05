LIBK_ROOT=libk

#LIBK_ARCHDIR:=$(LIBK_ROOT)/arch/$(ARCH)
#include $(LIBK_ARCHDIR)/make.config

LIBK_CFLAGS:=$(CFLAGS) --sysroot=$(PWD)/sysroot -isystem=$(INCLUDEDIR) -Wall -fbuiltin 

LIBK_FREEOBJS:=\
$(LIBK_ROOT)/stdio/printf.o\
$(LIBK_ROOT)/stdlib/itoa.o\
$(LIBK_ROOT)/string/memset.o\

LIBK_OBJS:= \
$(LIBK_FREEOBJS) \

LIBK_OBJS:=$(LIBK_FREEOBJS:.o=.libk.o)

LIBK_BINARIES=libk.a

.PHONY: libk_clean libk_install libk_install_headers libk_install_libs

libk.a: $(LIBK_OBJS)
	$(AR) -rcs $(LIBK_ROOT)/$@ $(LIBK_OBJS)

%.libk.o: %.asm
	$(AS) -felf32 $< -o $@

%.libk.o: %.c
	$(CC) -c $< -o $@ $(LIBK_CFLAGS)

libk_clean:
	rm -f $(LIBK_BINARIES) $(OBJS) $(LIBK_OBJS) *.o */*.o */*/*.o

libk_install: libk_install_headers libk_install_libs

libk_install_headers:
	mkdir -p $(DESTDIR)/$(INCLUDEDIR)
	cp -Rv $(LIBK_ROOT)/include/* $(DESTDIR)/$(INCLUDEDIR)/

libk_install_libs: $(LIBK_BINARIES)
	mkdir -p $(DESTDIR)/$(LIBDIR)
	cp -Rv $(LIBK_ROOT)/$(LIBK_BINARIES) $(DESTDIR)/$(LIBDIR)/




