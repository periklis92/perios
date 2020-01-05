#ifndef TTY_H
#define TTY_H 1

#include <sys/vga.h>

void cls(void);
void putc(int c);
void puts(char* s);
void putnum(int n);

#endif
