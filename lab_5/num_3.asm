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
    xor    %al, %al        
    call   printf            
     
    
    lea    S1(%rip), %rdi
    lea    8(%rsp), %rsi
    xor    %al, %al
    call    scanf            
   
    
    lea    S2(%rip), %rdi    
    xor    %al, %al        
    call   printf          
    
    
    lea    S12(%rip), %rdi
    lea    16(%rsp), %rsi
    xor    %al, %al
    call   scanf   
    
    
    movsd   8(%rsp), %xmm0
    movsd   16(%rsp), %xmm1
    mov     $2, %al 
    call    pow
    
    
    
    lea    S3(%rip), %rdi    
    
    xor    $1, %eax        
    call   printf            
    
    
    add    $40, %rsp         
    xor    %eax, %eax        
    ret 
