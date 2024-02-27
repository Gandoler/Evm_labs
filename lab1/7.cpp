#include <stdio.h>

int main() {
    // Задаем массив байтов
    unsigned char M_b[8] = {0xED, 0xED, 0xED, 0xED, 0xED, 0xED, 0xED, 0xED};

    // Вывод массива до ввода
    printf("Массив до ввода:\n");
    for (int i = 0; i < 8; ++i) {
        printf("%hhX ", M_b[i]); // Вывод в шестнадцатеричном формате
    }
    printf("\n");

    // Ввод нового значения для M_b[i], i = 2
    printf("Введите новое значение для M_b[2] (в шестнадцатеричной системе): ");
    if (scanf("%hhX", &M_b[2]) != 1) {
        printf("Ошибка ввода.\n");
        return 1;
    }

    // Вывод массива после ввода
    printf("Массив после ввода:\n");
    for (int i = 0; i < 8; ++i) {
        printf("%hhX ", M_b[i]); // Вывод в шестнадцатеричном формате
    }
    printf("\n");

    return 0;
}
