.data
msg: .string "Группа N1\n@ролов Глеб\пТрохин Евгений\n"
.text
.globl main
main: 
sub $8, %rsp 
lea msg(%rip), %rdi 
call puts
 add $8, %rsp
xor %eax, %eax 
ret


