    .data
    S0:     .string "Enter the value of x: \n"
    S1:     .string "%u"
    S12:    .string "%u"
    S2:     .string "Enter the value of y: \n"
    S3:     .string "Value of z: %u\n"
    S4:     .string "Value of w: %d\n"
    x:      .long 4294967295
    y:      .long 4294967295
    z:      .long 0 
    w:      .long 0 
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
       
        
        lea     S2(%rip), %rcx           
        call    printf          
        
        
        lea     S12(%rip), %rcx
        lea     y(%rip), %rdx
        call    scanf   
        
        
        mov     x,%eax
        mov     y,%ebx
        addl     %eax, %ebx
        setc    %cl
        mov     %rbx, z
    
                                                    
        movzbl  %cl, %ecx 
        movl    %ecx, w   
        
      
        
               
        lea     S3(%rip), %rcx   
        movl     z, %eax
        movq     %rax, %rdx
        call    printf 
             
        
        lea     S4(%rip), %rcx   
        movl     w, %eax
        movq     %rax, %rdx
        call    printf  
        
        add     $40, %rsp         
        xor     %eax, %eax        
        ret 

        
