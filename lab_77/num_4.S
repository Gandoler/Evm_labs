.data
S0:     .string "Enter the value of x: \n"
S1:     .string "%lf"
S3:     .string "Value of z: %d\n"
minus_one:      .long -1
eleven:      .double 11

.text
.globl main
main:
        movq %rsp, %rbp #for correct debugging 
    sub    $100, %rsp 
     
    
    
    lea     S0(%rip), %rcx           
    call    printf            
     
    
   lea    S1(%rip), %rcx
    lea   40(%rsp), %rdx
    call    scanf              
    
    
    movsd       40(%rsp),%xmm0
    movsd      eleven(%rip),%xmm1

    cmpnlesd      %xmm0,%xmm1
    
    movq     %xmm1,%rax
    mov    minus_one(%rip),%rbx
    imul    %rbx,%rax
    mov     %rax,44(%rsp)
 
    lea     S3(%rip), %rcx   
    movl     44(%rsp), %eax
    movq     %rax, %rdx
    call    printf 
    
    add     $100, %rsp         
    xor     %eax, %eax        
    ret 

    
