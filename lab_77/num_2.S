.data
S0:     .string "Enter the value of x: \n"
S1:     .string "%u"
S3:     .string "Value of z: %u\n"
x:      .long 0
z:      .long 0
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
    
    
    mov     x,%eax
    mov     $11,%ebx
    cmpl    %ebx,%eax
    setc    %al
    mov     %al,z
    
  
  
    lea     S3(%rip), %rcx   
    movl     z, %eax
    movq     %rax, %rdx
    call    printf 
    
    
    add     $40, %rsp         
    xor     %eax, %eax        
    ret 

    
