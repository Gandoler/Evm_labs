#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;

void Print_Dump(void* p, size_t N) {
    // Преобразование указателя в типизированный указатель на unsigned char
    unsigned char* p1 = reinterpret_cast<unsigned char*>(p);

    // Включаем шестнадцатеричный режим вывода для всех целых чисел
    printf("\n - значение в hex-%02hhX\n", *p1);

    // Вывод шестнадцатеричных значений байтов
    for (int i = 0; i < N; ++i) {
        printf("%d-номер-%02hhX\t", i, *(p1 + i));
    }
    printf("\n");

}


int main() {
    int x = 9;
    Print_Dump(&x, sizeof(x));
    printf("\n##############################################################################################################\n");

    // Пример массива из трёх целых чисел
    long long arr[] = { 9, -9, 0x88776155 };
    Print_Dump(&arr, sizeof(arr));
    printf("\n##############################################################################################################\n");

    // Пример числа с плавающей запятой y типа double
    double y = -9.0;
    Print_Dump(&y, sizeof(y));
    printf("\n##############################################################################################################\n");

    int z = 124319;
    Print_Dump(&z, sizeof(z));
    printf("\n##############################################################################################################\n");

    long long big = pow(2, 14);
    Print_Dump(&big, sizeof(big));
    printf("\n##############################################################################################################\n");

}
