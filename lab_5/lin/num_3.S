.data
S0:     .string "Enter the value of x: \n"
S1:     .string "%lf"
S12:    .string "%lf"
S2:     .string "Enter the value of y: \n"
S3:     .string "Value of z: %lf\n"
my_num_1:   .double 0
my_num_2:   .double 0
.text
.globl main
main: 
    sub    $40, %rsp  
    
    
    lea    S0(%rip), %rdi    
    xor    %al, %al        
    call   printf            
     
    
    lea    S1(%rip), %rdi
    lea    my_num_1(%rip), %rsi
    xor    %al, %al
    call    scanf            
   
    
    lea    S2(%rip), %rdi    
    xor    %al, %al        
    call   printf          
    
    
    lea    S12(%rip), %rdi
    lea    my_num_2(%rip), %rsi
    xor    %al, %al
    call   scanf   
    
    
    movsd   my_num_1(%rip), %xmm0
    movsd   my_num_2(%rip), %xmm1
    mov     $1, %al 
    call    pow
    
    
    
    lea    S3(%rip), %rdi    
    
    xor    $1, %eax        
    call   printf            
    
    
    add    $40, %rsp         
    xor    %eax, %eax        
    ret 
