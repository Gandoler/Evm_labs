#include <cstdio>
#define green "\033[32m"
#define white_def "\033[0m"



int main() {
    short Ms[] = {static_cast<short>(0xFADE), static_cast<short>(0xFADE), static_cast<short>(0xFADE), static_cast<short>(0xFADE), static_cast<short>(0xFADE)};
    int i = 2;

    printf("Ms (before) : ");
    for (int i = 0; i < 5; ++i) {
        if(i==2){
            printf(green);
        } 
        printf("%hd ", Ms[i]);
        printf(white_def);
    }
    printf("\n");

 
asm (
    
    "movl $2, %%eax\n\t"           // записываем размер шорта
    "imull %%ebx, %%eax\n\t"       // получаем смещение
    "leaq (%%rdx, %%rax), %%rdx\n\t"//%%rdx+%%rax добавляем смещение к адресу массива
    "movw $-1, (%%rdx)\n\t"       // изменяем значение элемента массива
:
: "b" (i), "c" (Ms)  // передаем размер элемента и адрес массива
: "memory"
);

    
    printf("Ms (after) : ");
    for (int i = 0; i < 5; ++i) {
        if(i==2){
            printf(green);
        } 
        printf("%hd ", Ms[i]);
        printf(white_def);
    }
    printf("\n");

    return 0;
}
