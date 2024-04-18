.data
S0:     .string "Enter the value of x: \n"
S1:     .string "%d"
S3:     .string "Value of z: %u\n"
x:      .long 0
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
    
    
    mov     x,%eax
    mov     eleven,%ebx
    cmpl    %ebx,%eax
    jl      set_one
back:      
    lea     S3(%rip), %rcx   
    movl     z, %eax
    movq     %rax, %rdx
    call    printf 
    
    
    add     $40, %rsp         
    xor     %eax, %eax        
    ret 

    
set_one:   
    mov $1,%eax
    mov %eax,z
    jmp back
        
