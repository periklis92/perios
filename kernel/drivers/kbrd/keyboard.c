#include <kernel/keyboard.h>
#include <sys/ports.h>
#include <stdio.h>

void keybrd_handler(registers_t);
int keybrd_get_char(int);

void keybrd_init(void){
    idt_add_handler(KEYBRD, keybrd_handler);
}

void keybrd_handler(registers_t r){
    int c = keybrd_get_char((int)inb(0x60));
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == '\n')
        putc(c);
}

int keybrd_get_char(int scode){
    return kbrd_buttons_array[scode];    
}