#ifndef INTERRUPTS_H
#define INTERRUPTS_H 1

#include <sys/cdefs.h> 
#include <common.h>

enum int_types{
    TIMER=0,
    KEYBRD
};

typedef struct registers_entry
{
   uint32_t ds;                  // Data segment selector
   uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax; // Pushed by pusha.
   uint32_t int_no, err_code;    // Interrupt number and error code (if applicable)
   uint32_t eip, cs, eflags, useresp, ss; // Pushed by the processor automatically.
} registers_t; 

struct idt_entry_struct{
    uint16_t offset_lowerbits;
    uint16_t selector;
    uint8_t zero;
    uint8_t type_attr;
    uint16_t offset_higherbits;
}__attribute__((packed));
typedef struct idt_entry_struct idt_t;

struct idt_ptr_struct{
    uint16_t limit;
    uint32_t base;
}__attribute__((packed));
typedef struct idt_ptr_struct idt_ptr_t;

typedef void (*handler)(registers_t r);

void init_interrupt_tables();
void _irq_handler(registers_t);
void idt_add_handler(uint8_t,handler);

#endif
