#include <stdio.h>
#define green "\033[32m"
#define white_def "\033[0m"

void insert_value_by_lea(long int *Mq, int i) {
    asm (
        "leaq (%%rax, %%rdx, 8), %%rax\n" // Получаем адрес Mq[i]
        "movb $0xBB, 1(%%rax)\n\t"        // Записываем байт 0xBB по адресу Mq[i] + 1
        :
        :"r"(Mq), "r"(i) 
    );
}

int main() {
    long int Mq[10]={0};  

    

    for(int i = 0; i < 10; i++){
        if(i==2){
             printf(green);
        } 
    printf("%016llx ", Mq[i]);
    printf("\n");
    printf(white_def);
    }
    printf("################\n");
    printf("\n");
    
    int index_to_insert = 2; 
    insert_value_by_lea(Mq, index_to_insert);

    for(int i = 0; i < 10; i++){
        if(i==2){
             printf(green);
        } 
    printf("%016llx ", Mq[i]);
    printf("\n");
    printf(white_def);
    }
    printf("\n");
    
    return 0;
}
