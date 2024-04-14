.globl main
.text

format_int32: .string "32-bit integer: %d\n"
main:
    subq $72, %rsp
    movq $1, %rcx   
    movq $2, %rdx    
    movq $3, %r8    
 
    movq $4, %r9 
 
    
    movq $5, 32(%rsp)   
    movq $6, 40(%rsp)    
    movq $7, 48(%rsp)    

    call   print_seven_and_return_2 


    lea     format_int32(%rip), %rcx
    movq     %rax, %rdx
    call    printf


    addq $72, %rsp      
    xor %rax, %rax      
    ret
