.data
S0:     .string "Enter the value of x: \n"
S0_1:     .string "Enter the value of y: \n"
S1:     .string "%lf"
S1_2:     .string "%lf"
S3:     .string "Value of z: %f\n"

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
    
    
    
    lea     S0_1(%rip), %rcx           
    call    printf            
    lea    S1_2(%rip), %rcx
    lea   48(%rsp), %rdx
    call    scanf                       
    
    
    movsd 40(%rsp), %xmm0
    mov $3, %rbx
    cvtsi2sd %rbx,%xmm1
    divsd    %xmm0,%xmm1
    
    
    movsd 48(%rsp), %xmm2
    mov $2, %rbx
    cvtsi2sd %rbx,%xmm0
   divsd    %xmm0,%xmm2
   
   addsd    %xmm2,%xmm1
   
   movsd 40(%rsp), %xmm0
    movsd 48(%rsp), %xmm2
    mulsd   %xmm0,%xmm2
    
    addsd    %xmm2,%xmm1
 
    lea     S3(%rip), %rcx   
    movl     56(%rsp), %eax
    movq     %xmm1, %rdx
    call    printf 
    
    add     $100, %rsp         
    xor     %eax, %eax        
    ret 

    
