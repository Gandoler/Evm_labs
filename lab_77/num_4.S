.data
S0:     .string "Enter the value of x: \n"
S1:     .string "%lf"
S3:     .string "Value of z: %u\n"
x:      .double 0
eleven:      .long 11
z:      .long 0 ;https://metanit.com/assembler/gas/9.13.php
.text
.globl main
main:
        movq %rsp, %rbp #for correct debugging 
    sub    $40, %rsp  
    
    
    lea     S0(%rip), %rcx           
    call    printf            
     
    
    lea     S1(%rip), %rcx
    lea     x(%rip), %rdx
    call    scanf             
    
    
    movsd       x,%xmm0
    cvtsi2sd       eleven,%xmm1

    cmpeqsd     %xmm0, %xmm1
     movq %xmm1,z
 
    lea     S3(%rip), %rcx   
    movl     z, %eax
    movq     %rax, %rdx
    call    printf 
    
    add     $40, %rsp         
    xor     %eax, %eax        
    ret 

    
