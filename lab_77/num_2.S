.data
S0:     .string "Enter the value of x: \n"
S1:     .string "%u"
S3:     .string "Value of z: %u\n"
.text
.globl main
main:
    movq %rsp, %rbp #for correct debugging 
    sub    $100, %rsp 
    
      
     mov     $11,%rax
    mov     %rax,36(%rsp)
    
    
    
    lea     S0(%rip), %rcx           
    call    printf            
     
    
    lea     S1(%rip), %rcx
    lea     40(%rsp), %rdx
    call    scanf             
    
    
    mov     40(%rsp),%eax
    mov     36(%rsp),%ebx
    cmpl    %ebx,%eax
    setc    %al
    mov     %al,44(%rsp)
    
  
  
    lea     S3(%rip), %rcx   
    mov     44(%rsp), %rdx
  
    call    printf 
    
    
    add     $100, %rsp         
    xor     %eax, %eax        
    ret 

    
