#include <stdio.h>
#define green "\033[32m"
#define white_def "\033[0m"


void insert_value(int *M, int i, short x);

int main() {
    int M[10] = {0};  
    int i = 5;
    short x = 10; 


    for(int i = 0; i < 10; i++){
        if(i==5){
         printf(green);
        } 
        printf("%08hx ", M[i]);
        printf(white_def);
    }
    printf("\n");
 
    insert_value(M, i, x);  

 
   for(int i = 0; i < 10; i++){
        if(i==5){
         printf(green);
        } 
        printf("%08hx ", M[i]);
        printf(white_def);
    }
    printf("\n");

    return 0;
}

void insert_value(int *M, int i, short x) {
    asm (
        // Сохраняем значение x в регистре %ax
        "movl %[x], %%eax\n"
        // Вычисляем адрес элемента в памяти: M + (i * размер элемента)
        "leaq (%%rdi, %%rsi, 4), %%rbx\n"
        // Записываем значение x в память по адресу M[i]
        "movl %%eax, (%%rbx)\n"
        :
        : "D" (M), "S" (i), [x]"m" (x) 
        : "ax", "bx"
    );
}
