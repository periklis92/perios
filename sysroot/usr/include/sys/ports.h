#ifndef PORT_H
#define PORT_H 1

#define outb(port, data)\
__asm__("outb %%al, %%dx" : : "a" (data), "d" (port))

#define inb(port)({\
unsigned char data;\
__asm__("inb %%dx, %%al" : "=a" (data) : "d" (port));\
data;\
})

#define outb_word(port, data)\
__asm__("out %%ax, %%dx" : : "a" (data), "d" (port))

#define inb_word(port)({\
unsigned short data;\
__asm__("in %%dx, %%ax" : "=a" (data) : "d" (port));\
data;\
})

#endif