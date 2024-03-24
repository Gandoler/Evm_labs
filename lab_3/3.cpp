#include <iostream>
using namespace std;
void print16(void* p) {
    // Преобразование указателя в типизированный указатель на uint16_t
    int16_t* p_value = reinterpret_cast<int16_t*>(p);
    // Беззнаковая интерпретация 16-битного целого числа в шестнадцатеричной системе
    printf("(a) Шестнадцатеричное представление (беззнаковое): %04X\n", *p_value);

    // Беззнаковая интерпретация 16-битного целого числа в двоичной системе
    printf("(б) Двоичное представление (беззнаковое): ");
    for (int i = 15; i >= 0; --i) {
        printf("%d", (*p_value >> i) & 1);
    }
    printf("\n");

    // Беззнаковая интерпретация 16-битного целого числа в десятичной системе
    printf("(в) Десятичное представление (беззнаковое): %u\n", *p_value);

    // Знаковая интерпретация 16-битного целого числа в шестнадцатеричной системе
    printf("(г) Шестнадцатеричное представление (знаковое): %04X\n", static_cast<int16_t>(*p_value));

    // Знаковая интерпретация 16-битного целого числа в двоичной системе
    printf("(д) Двоичное представление (знаковое): ");
    for (int i = 15; i >= 0; --i) {
        printf("%d", (static_cast<int16_t>(*p_value) >> i) & 1);
    }
    printf("\n");

    // Знаковая интерпретация 16-битного целого числа в десятичной системе
    printf("(е) Десятичное представление (знаковое): %d\n", static_cast<int16_t>(*p_value));
}
// Округление вниз до ближайшего кратного D
unsigned int round_down(unsigned int x, unsigned int D) {
    return x - (x % D);
}

// Округление вверх до ближайшего кратного D
unsigned int round_up(unsigned int x, unsigned int D) {
    return ((x + D - 1) / D) * D;
}

int main() {
    // Значение x из таблицы Л3.2
    unsigned int x = 42;

    // Значение D
    unsigned int D = 16;

    // Округление вниз
    unsigned int rounded_down = round_down(x, D);

    // Округление вверх
    unsigned int rounded_up = round_up(x, D);

    // Вывод результатов
    cout << "Исходное значение x: " << x << endl;
    cout << "Значение D: " << D << endl;
    cout << "Округление вниз: " << rounded_down << endl;
    cout << "Округление вверх: " << rounded_up << endl;


    print16(&x);
    printf("\nОкругленное вниз\n");
    print16(&rounded_down);
    printf("\nОкругление вверх\n");
    print16(&rounded_up);

    return 0;
}
