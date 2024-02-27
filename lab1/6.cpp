#include <stdio.h>

int main() {
    int M[5] = {1, 2, 3, 4, 5};
    
    // Вывод массива до ввода
    printf("Массив до ввода:\n");
    for (int i = 0; i < 5; ++i) {
        printf("%d ", M[i]);
    }
    printf("\n");

    // Ввод нового значения для M[2]
    printf("Введите новое значение для M[2]: ");
    if (scanf("%d", &M[2]) != 1) {
        printf("Ошибка ввода.\n");
        return 1;
    }

    // Вывод массива после ввода
    printf("Массив после ввода:\n");
    for (int i = 0; i < 5; ++i) {
        printf("%d ", M[i]);
    }
    printf("\n");

    return 0;
}
