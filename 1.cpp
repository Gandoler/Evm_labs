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

void print32(void* p) {
    // Целочисленные значения
    unsigned int uint_value = *reinterpret_cast<unsigned int*>(p);
    int int_value = *reinterpret_cast<int*>(p);

    // Значения типа float
    float float_value = *reinterpret_cast<float*>(p);

    // Вывод целочисленных значений
    printf("\n(а) Значение беззнакового целого: %08X\n", uint_value);
    printf("(б) Значение знакового целого: %d\n", int_value);

    // Вывод значений типа float в различных форматах
    printf("(в) Значение с плавающей запятой в фиксированной точке: %.2f\n", float_value);
    printf("(г) Значение с плавающей запятой в экспоненциальной записи: %.2e\n", float_value);
    printf("\n#########################################################################################################\n");
}

int main() {
    short m_signed = 231;
    unsigned short m_unsigned = 231;

    short n_signed = -33;
    unsigned short n_unsigned = -33;

    // Расширение знакового числа m до 32 бит
    int m_signed_extended = m_signed;
    // Расширение беззнакового числа m до 32 бит
    unsigned int m_unsigned_extended = m_unsigned;

    // Расширение знакового числа n до 32 бит
    int n_signed_extended = n_signed;
    // Расширение беззнакового числа n до 32 бит
    unsigned int n_unsigned_extended = n_unsigned;

    // Вывод значений до и после расширения
    cout << "Value of m_signed (16-bit): ";
    printf("\n");
    print16(&m_signed);
    printf("\n");

    cout << "Value of m_signed_extended (32-bit): ";
    printf("\n");
    print32(&m_signed_extended);
    printf("\n");

    cout << "Value of m_unsigned (16-bit): ";
    printf("\n");
    print16(&m_unsigned);
    printf("\n");

    cout << "Value of m_unsigned_extended (32-bit): ";
    printf("\n");
    print32(&m_unsigned_extended);
    printf("\n");

    cout << "Value of n_signed (16-bit): ";
    printf("\n");
    print16(&n_signed);
    printf("\n");

    cout << "Value of n_signed_extended (32-bit): ";
    printf("\n");
    print32(&n_signed_extended);
    printf("\n");

    cout << "Value of n_unsigned (16-bit): ";
    printf("\n");
    print16(&n_unsigned);
    printf("\n");

    cout << "Value of n_unsigned_extended (32-bit): ";
    printf("\n");
    print32(&n_unsigned_extended);
    printf("\n");

    return 0;
}
