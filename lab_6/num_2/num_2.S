.section .text
.globl calc_asm
calc_asm:
    sub     $8, %rsp
    subsd   %xmm0, %xmm1
    movq    %xmm1, %rax
    movsd    %xmm1, %xmm0

    add     $8, %rsp
    ret
