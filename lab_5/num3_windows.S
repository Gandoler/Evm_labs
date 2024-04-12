.data
S0:     .string "Enter the value of x: \n"
S1:     .string "%lf"
S12:    .string "%lf"
S2:     .string "Enter the value of y: \n"
S3:     .string "Value of z: %lf\n"
my_num_1:       .double 2
my_num_2:       .double 2
my_result:      .double 0 
.text
.globl main
main:
    movq %rsp, %rbp #for correct debugging 
    sub    $40, %rsp  
    
    
    lea    S0(%rip), %rcx           
    call   printf            
     
    
    lea    S1(%rip), %rcx
    lea    my_num_1(%rip), %rdx
    call    scanf            
   
    
    lea    S2(%rip), %rcx           
    call   printf          
    
    
    lea    S12(%rip), %rcx
    lea    my_num_2(%rip), %rdx
    call   scanf   
    
    
    movsd   my_num_1(%rip), %xmm0
    movsd   my_num_2(%rip), %xmm1
    call    pow
    movsd   %xmm0, my_result(%rip) 
    
    
    lea    S3(%rip), %rcx   
    mov    my_result, %rdx
    call   printf            
    
    
    add    $40, %rsp         
    xor    %eax, %eax        
    ret 
    
