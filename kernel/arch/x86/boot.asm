%define MULTIBOOT_HEADER_MAGIC 0x1BADB002
%define MULTIBOOT_PAGE_ALIGN (1 << 0)
%define MULTIBOOT_MEMORY_INFO (1 << 1)

MAGIC equ MULTIBOOT_HEADER_MAGIC
FLAGS equ MULTIBOOT_PAGE_ALIGN | MULTIBOOT_MEMORY_INFO
CHECKSUM equ -(MAGIC+FLAGS)

section .multiboot
align 4
    dd MAGIC
    dd FLAGS
    dd CHECKSUM
    dd 0
    dd 0
    dd 0
    dd 0
    dd 0
    dd 1024
    dd 768
    dd 0

section .bootstrap_stack, nobits
align 4
stack_bottom:
resb 16384
stack_top:

section .text
global _start
_start:
    mov esp, stack_top
    and esp, -16
    
    extern cls
    call cls

    push ebx
    push eax

    extern mboot
    call mboot

    extern init_gdt
    call init_gdt

    extern init_idt
    call init_idt
    

    extern keybrd_init
    call keybrd_init

    extern _init
    call _init

    extern kmain
    call kmain

    cli
.hang:
    hlt
    jmp .hang
