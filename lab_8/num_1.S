    .data
    S0:     .string "Enter the value of x: \n"
    S1:     .string "%d"
    S12:    .string "%d"
    S2:     .string "Enter the value of y: \n"
    S3:     .string "Value of z: %d\n"
 
    
    .text
    .globl main
    main:
        movq %rsp, %rbp #for correct debugging 
        sub    $100, %rsp  
        
        
        lea     S0(%rip), %rcx           
        call    printf            
         
        
        lea     S1(%rip), %rcx
        lea     40(%rsp), %rdx
        call    scanf            
       
        
        lea     S2(%rip), %rcx           
        call    printf          
        
        
        lea     S12(%rip), %rcx
        lea     44(%rsp), %rdx
        call    scanf   
        
        mov    40(%rsp),%rax
        mov    44(%rsp),%rbx
        imul    %rbx,%rax
        add     40(%rsp),%rax
        add     $-7,%rax
        mov    %rax, 48(%rsp)
               
        lea     S3(%rip), %rcx   
        movl     48(%rsp), %eax
        movq     %rax, %rdx
        call    printf 
             
        
      
        
        add     $100, %rsp         
        xor     %eax, %eax        
        ret 

        
