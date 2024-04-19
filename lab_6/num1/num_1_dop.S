.section .text
.globl calculate_asm
calculate_asm:
    sub $8, %rsp    
    lea -113(%rcx,%rdx,2),%rax
    add $8, %rsp
    ret
