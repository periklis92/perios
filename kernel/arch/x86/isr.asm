%macro _isr 1
    global isr%1
    isr%1:
        cli
        ; add esp, -2
        push byte 0
        push byte %1+32
        ; extern isr%1_handler
        ; call isr%1_handler
        jmp irq_common_stub
%endmacro 

section .text

_isr 0
_isr 1
_isr 2 
_isr 3
_isr 4 
_isr 5
_isr 6 
_isr 7
_isr 8 
_isr 9
_isr 10 
_isr 11
_isr 12
_isr 13
_isr 14
_isr 15

global load_idt
extern idt_ptr
load_idt:
    lidt [idt_ptr]
    ret

extern _irq_handler
irq_common_stub:
    pusha
    mov ax, ds
    push eax
    mov ax, 0x10 ; load the kernel data segment descriptor
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    call _irq_handler
    pop eax ; load the original data segment descriptor
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    popa
    add esp, 8
    sti
    iret
