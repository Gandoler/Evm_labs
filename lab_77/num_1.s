    .data
    S0:     .string "Enter the value of x: \n"
    S1:     .string "%u"
    S12:    .string "%u"
    S2:     .string "Enter the value of y: \n"
    S3:     .string "Value of z: %u\n"
    S4:     .string "Value of w: %d\n"  
    
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
        
        
        mov     40(%rsp),%eax
        mov     44(%rsp),%ebx
        addl     %eax, %ebx
        setc    %cl
        mov     %rbx, 48(%rsp)
    
                                                    
        movzbl  %cl, %ecx 
        movl    %ecx, 52(%rsp)  
        
      
        
               
        lea     S3(%rip), %rcx   
        movl     48(%rsp), %eax
        movq     %rax, %rdx
        call    printf 
             
        
        lea     S4(%rip), %rcx   
        movl     52(%rsp), %eax
        movq     %rax, %rdx
        call    printf  
        
        add     $100, %rsp         
        xor     %eax, %eax        
        ret 

        
