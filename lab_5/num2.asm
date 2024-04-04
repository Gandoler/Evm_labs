.data
format_int16: .string "16-bit integer: %d\n"
format_int32: .string "32-bit integer: %d\n"
format_int64: .string "64-bit integer: %lld\n"
format_float32: .string "32-bit float: %f\n"
format_float64: .string "64-bit float: %f\n"


.text
myFlotik:  .float 3.14
myDoublik: .float 3.14159265359
.globl main
main: 
    sub     $40, %rsp
    
    movw    $6535, 2(%rsp)
    movl    $23, 6(%rsp)
    movq    $23234234, 14(%rsp)
   
    movss   myFlotik(%rip), %xmm0
    movss   %xmm0, 22(%rsp)
    
    
    
    movss   myDoublik(%rip), %xmm1
    movss   %xmm1, 32(%rsp)
    
    mov     2(%rsp), %eax
    mov     %eax, %esi
    lea     format_int16(%rip), %rdi  
    xor     %eax, %eax
    call    printf
    
    mov     6(%rsp), %eax
    mov     %eax, %esi
    lea     format_int32(%rip), %rdi  
    xor     %eax, %eax
    call    printf
    
    mov     14(%rsp), %rax
    mov     %rax, %rsi
    lea     format_int64(%rip), %rdi  
    xor     %eax, %eax
    call    printf
    
    
    cvtss2sd    22(%rsp), %xmm0
    lea     format_float32(%rip), %rdi 
    mov     $1,%al 
    call    printf
   
    
   
    cvtss2sd    32(%rsp), %xmm0
    lea     format_float64(%rip), %rdi 
    mov     $1,%al 
    call    printf
    
    
    add     $40, %rsp
    xor     %eax, %eax
    ret



