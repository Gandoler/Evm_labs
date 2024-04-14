.globl num1
.data
first_kef: .long 2
tmp: .long -113

.text

num1:
    sub     $110, %rsp
    add     %rcx, tmp
    mov     first_kef,%ebx
    imul    %edx, %ebx
    mov     tmp, %eax
    add     %ebx, %eax 
    add      $110, %rsp         
    xor    %eax, %eax        
    ret 
    
