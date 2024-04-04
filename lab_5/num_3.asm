.file "mm.c"   


.data
S0:    .string "Enter the value of x: \n"
S1:    .string "%lf"
S2:    .string "Enter the value of y: \n"
S3:    .string "Value of z: %lf\n"

.text
.globl main
main: 
    sub    $64, %rsp         
    lea    S0(%rip), %rdi    
    xor    %eax, %eax        
    call   printf            
     
    
    push %rbp
    leaq    8(%rsp), %rax
    movq    %rax, %rsi
    lea    S1(%rip), %rdi
    movl    $0, %eax
    call    scanf            
    pop %rbp
    
    lea    S2(%rip), %rdi    
    xor    %eax, %eax        
    call   printf          
    
    
    push %rbp
    leaq    16(%rsp), %rax
    movq    %rax, %rsi
    lea    S1(%rip), %rdi
    movl    $0, %eax
    call   scanf   
    pop %rbp
    
  
    
    movsd   8(%rsp), %xmm0
    movq    16(%rsp), %rax
    movapd  %xmm0, %xmm1
    movq    %rax, %xmm0
    call    pow
   
    
    
    lea    S3(%rip), %rdi    
    movq    %xmm0, %rsi
    xor    %eax, %eax        
    call   printf            
    
    
    add    $64, %rsp         
    xor    %eax, %eax        
    ret 
