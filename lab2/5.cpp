#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;

void print32(void* p) {
    // Целочисленные значения
    unsigned int uint_value = *reinterpret_cast<unsigned int*>(p);
    int int_value = *reinterpret_cast<int*>(p);

    // Значения типа float
    float float_value = *reinterpret_cast<float*>(p);

    // Вывод целочисленных значений
    printf("Значение беззнакового целого: %u\n", uint_value);
    printf("Значение знакового целого: %d\n", int_value);

    // Вывод значений типа float в различных форматах
    printf("Значение с плавающей запятой в фиксированной точке: %.2f\n", float_value);
    printf("Значение с плавающей запятой в экспоненциальной записи: %.2e\n", float_value);
    printf("\n##############################################################################################################\n");
}


int main() {
    unsigned int uint_val = 4294967295; // Максимальное 32-битное значение без знака
    int int_val = -2147483648; // Минимальное 32-битное значение со знаком
    float float_val = 123.456f; // Пример значения float

    int x = 9, y = -9, z = 0x88776155;
    float x_f = 9, y_f = -9, z_f = 0x88776155;
    printf("unsigned int\n");
    print32(&uint_val);
    printf("int\n");
    print32(&int_val);
    printf("float\n");
    print32(&float_val);


    printf("int ----- x\n");
    print32(&x);
    printf("int ----- y\n");
    print32(&y);
    printf("int ----- z\n");
    print32(&z);




    printf("float ----- x_f\n");
    print32(&x_f);
    printf("float ----- y_f\n");
    print32(&y_f);
    printf("float ----- z_f\n");
    print32(&z_f);

}
