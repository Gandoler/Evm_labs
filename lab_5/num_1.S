.data
msg: .string "\ngroup N1\tFRolov Gleb\tTrochin Evgeniy\n"
.text
.globl main
main: 
    sub $8, %rsp 
    lea msg(%rip), %rdi 
    call puts
    add $8, %rsp
    xor %eax, %eax 
    ret
