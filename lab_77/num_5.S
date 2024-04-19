.data
S0:     .string "Enter the value of x: \n"
S1:     .string "%d"
S3:     .string "Value of z: %d\n"
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
    lea     23(%eax,%eax,4),%eax
     mov    %eax,x
    
    mov     $5,%ebx
    cmpl    %eax,%ebx
    jg       set_minus_one
    mov     %eax,z
    back:
  
  
    lea     S3(%rip), %rcx   
    movl     z, %eax
    movq     %rax, %rdx
    call    printf 
    
    
    add     $40, %rsp         
    xor     %eax, %eax        
    ret 
set_minus_one:
    mov   $-1,%eax
    mov     %eax,z
    jmp back
    
