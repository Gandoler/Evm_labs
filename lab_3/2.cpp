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
int main() {
    // Значения m и n из таблицы Л3.1
    short m = 231;
    short n = -33;

    // Знаковое умножение на 2
    short m_signed_multiply_by_2 = m * 2;
    short n_signed_multiply_by_2 = n * 2;

    // Беззнаковое умножение на 2
    unsigned short m_unsigned_multiply_by_2 = static_cast<unsigned short>(m) * 2;
    unsigned short n_unsigned_multiply_by_2 = static_cast<unsigned short>(n) * 2;

    // Знаковое деление на 2
    short m_signed_divide_by_2 = m / 2;
    short n_signed_divide_by_2 = n / 2;

    // Беззнаковое деление на 2
    unsigned short m_unsigned_divide_by_2 = static_cast<unsigned short>(m) / 2;
    unsigned short n_unsigned_divide_by_2 = static_cast<unsigned short>(n) / 2;

    // Расчёт остатка от беззнакового деления на 16
    unsigned short m_remainder_by_16 = static_cast<unsigned short>(m) % 16;
    unsigned short n_remainder_by_16 = static_cast<unsigned short>(n) % 16;

    // Округление вниз до числа, кратного 16 (беззнаковое)
    unsigned short m_round_down_to_multiple_of_16 = (m / 16) * 16;
    unsigned short n_round_down_to_multiple_of_16 = (n / 16) * 16;

    // Знаковый сдвиг влево на 1 бит
    short m_signed_shift_left_by_1 = m << 1;
    short n_signed_shift_left_by_1 = n << 1;

    // Беззнаковый сдвиг влево на 1 бит
    unsigned short m_unsigned_shift_left_by_1 = static_cast<unsigned short>(m) << 1;
    unsigned short n_unsigned_shift_left_by_1 = static_cast<unsigned short>(n) << 1;

    // Знаковый сдвиг вправо на 1 бит
    short m_signed_shift_right_by_1 = m >> 1;
    short n_signed_shift_right_by_1 = n >> 1;

    // Беззнаковый сдвиг вправо на 1 бит
    unsigned short m_unsigned_shift_right_by_1 = static_cast<unsigned short>(m) >> 1;
    unsigned short n_unsigned_shift_right_by_1 = static_cast<unsigned short>(n) >> 1;

    // Рассчитывает x & 15
    unsigned short m_and_15 = m & 15;
    unsigned short n_and_15 = n & 15;

    // Рассчитывает x & -16
    short m_and_minus_16 = m & -16;
    short n_and_minus_16 = n & -16;

    // Вывод результатов
    cout << "m_signed_multiply_by_2: ";
    print16(&m_signed_multiply_by_2);
    cout << "n_signed_multiply_by_2: ";
    print16(&n_signed_multiply_by_2);
    printf("\n\n");

    cout << "m_unsigned_multiply_by_2: ";
    print16(&m_unsigned_multiply_by_2);
    cout << "n_unsigned_multiply_by_2: ";
    print16(&n_unsigned_multiply_by_2);
    printf("\n\n");

    cout << "m_signed_divide_by_2: ";
    print16(&m_signed_divide_by_2);
    cout << "n_signed_divide_by_2: ";
    print16(&n_signed_divide_by_2);
    printf("\n\n");

    cout << "m_unsigned_divide_by_2: ";
    print16(&m_unsigned_divide_by_2);
    cout << "n_unsigned_divide_by_2: ";
    print16(&n_unsigned_divide_by_2);
    printf("\n\n");

    cout << "m_remainder_by_16: ";
    print16(&m_remainder_by_16);
    cout << "n_remainder_by_16: ";
    print16(&n_remainder_by_16);
    printf("\n\n#########################################\n\n");
    printf("\n\n");

    cout << "m_round_down_to_multiple_of_16: ";
    print16(&m_round_down_to_multiple_of_16);
    cout << "n_round_down_to_multiple_of_16: ";
    print16(&n_round_down_to_multiple_of_16);
    printf("\n\n");

    cout << "m_signed_shift_left_by_1: ";
    print16(&m_signed_shift_left_by_1);
    cout << "n_signed_shift_left_by_1: ";
    print16(&n_signed_shift_left_by_1);
    printf("\n\n");

    cout << "m_unsigned_shift_left_by_1: ";
    print16(&m_unsigned_shift_left_by_1);
    cout << "n_unsigned_shift_left_by_1: ";
    print16(&n_unsigned_shift_left_by_1);
    printf("\n\n");

    cout << "m_signed_shift_right_by_1: ";
    print16(&m_signed_shift_right_by_1);
    cout << "n_signed_shift_right_by_1: ";
    print16(&n_signed_shift_right_by_1);
    printf("\n\n");

    cout << "m_unsigned_shift_right_by_1: ";
    print16(&m_unsigned_shift_right_by_1);
    cout << "n_unsigned_shift_right_by_1: ";
    print16(&n_unsigned_shift_right_by_1);
    printf("\n\n");

    cout << "m_and_15: ";
    print16(&m_and_15);
    cout << "n_and_15: ";
    print16(&n_and_15);
    printf("\n\n");

    cout << "m_and_minus_16: ";
    print16(&m_and_minus_16);
    cout << "n_and_minus_16: ";
    print16(&n_and_minus_16);
    printf("\n\n");

    return 0;
}
