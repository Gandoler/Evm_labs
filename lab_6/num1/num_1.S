.section .text
.globl calculate_asm
calculate_asm:
    sub $8, %rsp
    mov %rcx, %rax
    mov $-113, %rbx
    add %rdx, %rdx
    add %rdx, %rax
    add %rbx, %rax
    add $8, %rsp
    ret
