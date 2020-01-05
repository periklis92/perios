#ifndef KEYBOARD_H
#define KEYBOARD_H 1

#include <common.h>
#include <kernel/interrupts.h>
#include <sys/tty.h>

int kbrd_buttons_array[128] = {
    0, 27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    '-', '=', 8, 9, 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o',
    'p', '[', ']', '\n', 0/*L Ctrl*/, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k',
    'l', ';', '\'', '`', 0/*L Shift*/, '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm',
    ',', '.', '/', 0/*R Shift*/, '*'
};

void keybrd_init(void);

#endif