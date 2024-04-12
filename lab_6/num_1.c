#include <stdio.h>

extern int num1(int arg1, int arg2); // Объявляем num1 как функцию, принимающую два int аргумента и возвращающую int

int main() {
    int result;
    int arg1 = 10;   // Пример значения для регистра %rcx
    int arg2 = 5;    // Пример значения для регистра %edx
    
    result = num1(arg1, arg2); // Вызываем функцию num1
    
    printf("Результат: %d\n", result);
    /*printf("hello world\n");*/
    return 0;
}
