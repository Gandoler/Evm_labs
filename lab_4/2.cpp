#include <cstdio>
#define green "\033[32m"
#define white_def "\033[0m"

int main() {
    short Ms[] = {static_cast<short>(0xFADE), static_cast<short>(0xFADE), static_cast<short>(0xFADE), static_cast<short>(0xFADE), static_cast<short>(0xFADE)};
    int i = 2;

    printf("Ms (after) : ");
    for (int i = 0; i < 5; ++i) {
        if(i==2){
            printf(green);
        } 
        printf("%hd ", Ms[i]);
        printf(white_def);
    }
    printf("\n");

 
 asm (
    "movw $-1, %%ax\n"        // Загрузка значения -1 в регистр ax
    "mov %0, %%rbx\n\t"         // Загрузка адреса массива Ms в регистр rbx
    "mov %1, %%esi\n\t"         // Загрузка индекса i в регистр esi
    "shl $1, %%esi\n\t"         // Умножение индекса на размер short
    "add %%rsi, %%rbx\n\t"      // Прибавление смещения к адресу массива
    "movw %%ax, (%%rbx)\n\t"    // Вставка значения по адресу (Ms + i * sizeof(short))
    :
    : "r" (Ms), "r" (i)
    : "rbx", "rsi", "rax", "memory"
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
