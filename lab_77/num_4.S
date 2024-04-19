.data
S0:     .string "Enter the value of x: \n"
S1:     .string "%lf"
S3:     .string "Value of z: %d\n"
x:      .double 1
eleven:      .double 11
z:      .long 0 
.text
.globl main
main:
        movq %rsp, %rbp #for correct debugging 
    sub    $40, %rsp  
    
    
    lea     S0(%rip), %rcx           
    call    printf            
     
    
   lea    S1(%rip), %rcx
    lea    x(%rip), %rdx
    call    scanf              
    
    
    movsd       x,%xmm0
    movsd       eleven,%xmm1

    cmpnlesd      %xmm0,%xmm1
    
    movq     %xmm1,%rax
    mov     $-1,%rbx
    imul    %rbx,%rax
    mov     %rax,z
 
    lea     S3(%rip), %rcx   
    movl     z, %eax
    movq     %rax, %rdx
    call    printf 
    
    add     $40, %rsp         
    xor     %eax, %eax        
    ret 

    
