.data
S0:    .string "Enter the value of x: \n"
S1:    .string "%lf"
S12:    .string "%lf"
S2:    .string "Enter the value of y: \n"
S3:    .string "Value of z: %lf\n"

.text
.globl main
main: 
    sub    $40, %rsp         
    lea    S0(%rip), %rdi    
    xor    %eax, %eax        
    call   printf            
     
    
    
    leaq    8(%rsp), %rax
    movq    %rax, %rsi
    lea    S1(%rip), %rdi
    movl    $0, %eax
    call    scanf            
   
    
    lea    S2(%rip), %rdi    
    xor    %eax, %eax        
    call   printf          
    
    
    
    leaq    16(%rsp), %rax
    movq    %rax, %rsi
    lea    S12(%rip), %rdi
    movl    $0, %eax
    call   scanf   
    
    
  
    
    movsd   8(%rsp), %xmm0
    movsd    16(%rsp), %xmm1
    call    pow
    
    
    
    lea    S3(%rip), %rdi    
    movq    %xmm0, %rsi
    xor    $1, %eax        
    call   printf            
    
    
    add    $40, %rsp         
    xor    %eax, %eax        
    ret 
