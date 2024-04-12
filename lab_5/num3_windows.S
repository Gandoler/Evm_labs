.data
S0:    .string "Enter the value of x: \n"
S1:    .string "%lf"
S12:    .string "%lf"
S2:    .string "Enter the value of y: \n"
S3:    .string "Value of z: %lf\n"

.text
.globl main
main: 
    sub    $32, %rsp  
    

    lea    S0(%rip), %rcx          
    call   printf            ;32
   
      
   
    lea    S1(%rip), %rcx   
    lea    32(%rsp), %rdx
    call    scanf            
   
    
    lea    S2(%rip), %rcx           
    call   printf          
    
    
    lea    S12(%rip), %rcx
    lea    16(%rsp), %rdx
    call   scanf   
    
    
  ;  movsd   8(%rsp), %xmm0
;    movsd   16(%rsp), %xmm1
;    call    pow
;    
    
    
    lea    S3(%rip), %rcx           
    call   printf            
    
    
    add    $40, %rsp         
    xor    %eax, %eax        
    ret 
