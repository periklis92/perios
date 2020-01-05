#include <kernel/interrupts.h>
#include <sys/ports.h>
#include <string.h>
#include <stdio.h>

void* ext_handlers[16]={
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0
};

idt_t IDT[256];
idt_ptr_t idt_ptr;

extern int load_idt();
void idt_add_entry(uint32_t, uint8_t);
void init_idt(void){
    idt_ptr.limit = (sizeof(idt_t) * 256) -1;
    idt_ptr.base = (uint32_t)&IDT[0];

    memset(&IDT, 0, (sizeof(idt_t) * 256));
    
    outb(0x20, 0x11);
    outb(0xA0, 0x11);
    outb(0x21, 0x20);
    outb(0xA1, 0x28);
    outb(0x21, 0x04);
    outb(0xA1, 0x02);
    outb(0x21, 0x01);
    outb(0xA1, 0x01);
    outb(0x21, 0x0);
    outb(0xA1, 0x0);

    extern void isr0();
    extern void isr1();
    extern void isr2();
    extern void isr3();
    extern void isr4();
    extern void isr5();
    extern void isr6();
    extern void isr7();
    extern void isr8();
    extern void isr9();
    extern void isr10();
    extern void isr11();
    extern void isr12();
    extern void isr13();
    extern void isr14();
    extern void isr15();

    idt_add_entry((unsigned)isr0, 32);
    idt_add_entry((unsigned)isr1, 33);
    idt_add_entry((unsigned)isr2, 34);
    idt_add_entry((unsigned)isr3, 35);
    idt_add_entry((unsigned)isr4, 36);
    idt_add_entry((unsigned)isr5, 37);
    idt_add_entry((unsigned)isr6, 38);
    idt_add_entry((unsigned)isr7, 39);
    idt_add_entry((unsigned)isr8, 40);
    idt_add_entry((unsigned)isr9, 41);
    idt_add_entry((unsigned)isr10, 42);
    idt_add_entry((unsigned)isr11, 43);
    idt_add_entry((unsigned)isr12, 44);
    idt_add_entry((unsigned)isr13, 45);
    idt_add_entry((unsigned)isr14, 46);
    idt_add_entry((unsigned)isr15, 47);

    load_idt();
}

void idt_add_handler(uint8_t num, handler _handler){
    ext_handlers[num] = _handler;
}

void idt_add_entry(uint32_t _isr, uint8_t i){
    IDT[i].offset_lowerbits = (_isr ) & 0xFFFF;
    IDT[i].selector = 0x08;
    IDT[i].zero = 0;
    IDT[i].type_attr = 0x8E;
    IDT[i].offset_higherbits = (_isr >> 16) & 0xFFFF;
}

void _irq_handler(registers_t r){
    handler _h;
    uint32_t no = r.int_no;
    _h = ext_handlers[no-32];
    if (_h){
        _h(r);
    }

    if (r.int_no >= 40){
        outb(0xA0, 0x20);
    }

    outb(0x20, 0x20);
}