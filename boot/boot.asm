bits 32

section .multiboot
align 4
    dd 0x1BADB002
    dd 0x00
    dd -(0x1BADB002 + 0x00)

section .bss
align 16
stackBottom:
    resb 16384
stackTop:

section .text
global _start
extern kernelMain

_start:
    mov esp, stackTop
    call kernelMain
    cli
    hlt