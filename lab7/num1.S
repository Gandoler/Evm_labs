    .data
    S0:     .string "Enter the value of x: \n"
    S1:     .string "%d"
    S12:    .string "%d"
    S2:     .string "Enter the value of y: \n"
    S3:     .string "Value of z: %d\n"
    S4:     .string "Value of w: %d\n"
    x:      .long 0
    y:      .long 0
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
         js carry_set 
        mov     %rbx, z
    
    
        xor %rax,%rax
        lahf
               
        lea     S3(%rip), %rcx   
        movl     z, %eax
        movq     %rax, %rdx
        call    printf 
        
                   
                              
                                         
        xor     %rcx,%rcx                                                 
        mov     %rcx, w
             
        
        lea     S4(%rip), %rcx   
        movl     w, %eax
        movq     %rax, %rdx
        call    printf  
        
        add     $40, %rsp         
        xor     %eax, %eax        
        ret 
        
    carry_set:             
        mov     $1, %rdi
        mov     %rdi,w 
         lea     S4(%rip), %rcx   
        movl     w, %eax
        movq     %rax, %rdx
        call    printf
        add     $40, %rsp         
        xor     %eax, %eax        
        ret 
        
