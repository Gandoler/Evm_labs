.data
format_int16: .string "16-bit integer: %d\n"
format_int32: .string "32-bit integer: %d\n"
format_int64: .string "64-bit integer: %lld\n"
format_float32: .string "32-bit float: %f\n"
format_float64: .string "64-bit float: %lf\n"
myShortik:  .short 1235
myLongik:   .long 134656
myQuad:     .quad 1241246
myFlotik:   .float 3.14
myDoublik:  .double 3.14159265359

.text

.globl main
main:
    movq %rsp, %rbp #for correct debugging 
    sub     $110, %rsp
  
    mov     myShortik(%rip), %ax
    mov     %ax, (%rsp)
    mov     myLongik(%rip), %eax
    mov     %eax, 34(%rsp)
    mov     myQuad(%rip), %rax
    mov     %rax, 70(%rsp)
   
    
    lea     format_int16(%rip), %rcx
    xor     %rdx,%rdx
    mov     (%rsp), %rdx
    call    printf
   
    
   
    
    lea     format_int32(%rip), %rcx
    xor     %rdx,%rdx
    mov     34(%rsp), %rdx
    call    printf
    
    
    lea     format_int64(%rip), %rcx 
    xor     %rdx,%rdx
    mov     70(%rsp), %rdx
    call    printf
    
    
    add     $110, %rsp
    sub     $110, %rsp
    
    
    movsd   myFlotik(%rip), %xmm0
    cvtss2sd  %xmm0, %xmm0
    movsd   %xmm0, (%rsp)
  
    movsd   myDoublik(%rip), %xmm1
    movsd   %xmm1, 40(%rsp)
   
    
    
    lea     format_float32(%rip), %rcx 
    xor     %rdx,%rdx
    mov     (%rsp), %rdx
    
      
      
    call    printf
   
    
    lea     format_float64(%rip), %rcx 
    xor     %rdx,%rdx
    mov    40(%rsp), %rdx
    call    printf
    
    
    add     $110, %rsp
    xor     %eax, %eax
    ret
    
    
