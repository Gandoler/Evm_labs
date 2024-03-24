#include <iostream>
#include <cstdint>

float absolute(float x) {
    uint32_t* ptr = reinterpret_cast<uint32_t*>(&x); // Получаем указатель на переменную с плавающей запятой
    uint32_t mask = 0x7FFFFFFF; // Маска для сброса бита знака
    *ptr = *ptr & mask; // Применяем маску
    return *reinterpret_cast<float*>(ptr); // Возвращаем модуль числа
}

int main() {
    float x = -5.25; 
   
    printf("|x| = %f\n", absolute(x));
    x = -3.23233; 
   
    printf("|x| = %f\n", absolute(x));
  
    return 0;
}
