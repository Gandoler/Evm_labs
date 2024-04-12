.data
format_int16:       .string "16-bit integer: %d\n"
format_int32:       .string "32-bit integer: %d\n"
format_int64:       .string "64-bit integer: %lld\n"
format_float32:     .string "32-bit float: %f\n"
format_float64:     .string "64-bit float: %f\n"
myShortik:  .short 1235
myLongik:   .long 134656
myQuad:     .quad 1241246
myFlotik:   .float 3.14
myDoublik:  .double 3.14159265359


.text

.globl main
main: 
    sub     $40, %rsp
    
    mov     myShortik(%rip), %ax
    mov     %ax, 2(%rsp)
    mov     myLongik(%rip), %eax
    mov     %eax, 6(%rsp)
    mov     myQuad(%rip), %rax
    mov     %rax, 14(%rsp)
   
   
    movss   myFlotik(%rip), %xmm0
    movss   %xmm0, 22(%rsp)
    movsd   myDoublik(%rip), %xmm1
    movsd   %xmm1, 32(%rsp)
    
    
    lea     format_int16(%rip), %rdi
    mov     2(%rsp), %rsi
    xor     %al, %al
    call    printf
    
    
    lea     format_int32(%rip), %rdi  
    mov     6(%rsp), %rsi
    xor     %al, %al
    call    printf
    
    
    lea     format_int64(%rip), %rdi 
    mov     14(%rsp), %rsi
    xor     %al, %al
    call    printf
    
    
    lea     format_float32(%rip), %rdi 
    cvtss2sd    22(%rsp), %xmm0
    mov     $1,%al 
    call    printf
   
    
    lea     format_float64(%rip), %rdi 
    movsd   32(%rsp), %xmm0
    mov     $1,%al 
    call    printf
    
    
    add     $40, %rsp
    xor     %eax, %eax
    ret
