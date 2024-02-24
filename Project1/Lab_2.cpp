#include <iostream>
using namespace std;




#pragma region Num_1
void viewPointer(void* p) {
    // Преобразование указателя в типизированные
    char* p1 = reinterpret_cast<char*>(p);
    unsigned short* p2 = reinterpret_cast<unsigned short*>(p);
    double* p3 = reinterpret_cast<double*>(p);

    // Печать адресов
    printf("Address of p: %p\n", p);
    printf("Address of p1: %p\n", reinterpret_cast<void*>(p1));
    printf("Address of p2: %p\n", reinterpret_cast<void*>(p2));
    printf("Address of p3: %p\n", reinterpret_cast<void*>(p3));


    cout << "\n" << p1 << "\t" << *p1 << endl;
    cout << "\n" << p2 << "\t" << *p2 << endl;
    cout << "\n" << p3 << "\t" << *p3 << endl;

    // Печать смежных адресов
    printf("Address of p1 + 1: %p\n", reinterpret_cast<void*>(p1 + 1));
    printf("Address of p2 + 1: %p\n", reinterpret_cast<void*>(p2 + 1));
    printf("Address of p3 + 1: %p\n", reinterpret_cast<void*>(p3 + 1));

    // Размеры типов
    size_t size_char = sizeof(char);
    size_t size_ushort = sizeof(unsigned short);
    size_t size_double = sizeof(double);

    // Разница между адресами
    printf("Difference between p1 and p1 + 1 in bytes: %zu\n", size_char);
    printf("Difference between p2 and p2 + 1 in bytes: %zu\n", size_ushort);
    printf("Difference between p3 and p3 + 1 in bytes: %zu\n", size_double);
}
void Num1() {
    int num = 42;
    viewPointer(&num); // Пример вызова функции с адресом переменной num
}
#pragma endregion

#pragma region Num_2
void PrintPointer(void* p)
{
    char* p1 = reinterpret_cast<char*>(p);
    unsigned short* p2 = reinterpret_cast<unsigned short*>(p);
    double* p3 = reinterpret_cast<double*>(p);

    printf("Value at p1: 0x%x\n", *p1);
    printf("Value at p2: 0x%x\n", *p2);
    printf("Value at p3: 0x%x\n", *reinterpret_cast<int*>(p3));

    // Печать значений по смежным адресам p1 + 1, p2 + 1, p3 + 1
    printf("Value at p1 + 1: 0x%x\n", *(p1 + 1));
    printf("Value at p2 + 1: 0x%x\n", *(p2 + 1));
    printf("Value at p3 + 1: 0x%x\n", *reinterpret_cast<int*>(p3 + 1));
}

void Num2() {
    long long value1 = 0x1122334455667788LL;
    PrintPointer(&value1);
    char value2[] = "0123456789abcdef";
    PrintPointer(&value2);
}
#pragma endregion

#pragma region Num_3
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

void Num3() {
    int x = 9;
    Print_Dump(&x, sizeof(x));
    printf("\n##############################################################################################################\n");

    // Пример массива из трёх целых чисел
    int arr[] = { 9, -9, 0x88776155 };
    Print_Dump(&arr, sizeof(arr));
    printf("\n##############################################################################################################\n");

    // Пример числа с плавающей запятой y типа double
    double y = -9.0;
    Print_Dump(&y, sizeof(y));
    printf("\n##############################################################################################################\n");

    int z = 124319;
    Print_Dump(&z, sizeof(z));
    printf("\n##############################################################################################################\n");

    int big = pow(2, 14);
    Print_Dump(&big, sizeof(big));
    printf("\n##############################################################################################################\n");

}
#pragma endregion


#pragma region Num_4

void print16(void* p) {
    // Преобразование указателя в типизированный указатель на uint16_t
    uint16_t* p_value = reinterpret_cast<uint16_t*>(p);
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
    printf("(г) Шестнадцатеричное представление (знаковое): %04X\n", static_cast<uint16_t>(*p_value));

    // Знаковая интерпретация 16-битного целого числа в двоичной системе
    printf("(д) Двоичное представление (знаковое): ");
    for (int i = 15; i >= 0; --i) {
        printf("%d", (static_cast<int16_t>(*p_value) >> i) & 1);
    }
    printf("\n");

    // Знаковая интерпретация 16-битного целого числа в десятичной системе
    printf("(е) Десятичное представление (знаковое): %d\n", static_cast<int16_t>(*p_value));
}
void Num4() {
    // Примеры значений 16-битных целых чисел
    uint16_t val1 = 0x88776155;
    print16(&val1);

    int16_t val2 = -9;
    print16(&val2);
}
#pragma endregion


#pragma region Num_5
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
void Num5() {
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
#pragma endregion

#pragma region Num_6
void print64(void* p) {
    unsigned long long ull_value = *reinterpret_cast<unsigned long long*>(p);
    long long ll_value = *reinterpret_cast<long long*>(p);

    double double_value = *reinterpret_cast<double*>(p);

    printf("Значение беззнакового целого 64 бит: %llu\n", ull_value);
    printf("Значение знакового целого 64 бит: %lld\n", ll_value);

    printf("Значение с плавающей запятой (double) в фиксированной точке: %.2f\n", double_value);
    printf("Значение с плавающей запятой (double) в экспоненциальной записи: %.2e\n", double_value);
}
void NUM6() {
    unsigned long long ull_val = 18446744073709551615ULL;
    long long ll_val = -922337203685LL;
    double double_val = 1234567890.123456789;


    print64(&ull_val);
    print64(&ll_val);
    print64(&double_val);
}
#pragma endregion


#pragma region Num_7
void printDump(void* addr, size_t size) {
    unsigned char* ptr = reinterpret_cast<unsigned char*>(addr);

    for (size_t i = 0; i < size; ++i) {
        printf("%02X ", ptr[i]);
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}
void Num7() {
    const char* char_str = "jzyx";
    const char* russian_char_str = "ёяюэ";
    const wchar_t* wide_char_str = L"jzyx";
    const wchar_t* russian_wide_char_str = L"ёяюэ";

    printf("Дамп памяти для строки \"jzyx\":\n");
    printDump(&char_str, sizeof(char_str));

    printf("\nДамп памяти для строки \"ёяюэ\":\n");
    printDump(&russian_char_str, sizeof(russian_char_str));

    printf("\nДамп памяти для широкой строки L\"jzyx\":\n");
    printDump(&wide_char_str, sizeof(wide_char_str));

    printf("\nДамп памяти для широкой строки L\"ёяюэ\":\n");
    printDump(&russian_wide_char_str, sizeof(russian_wide_char_str));

}
#pragma endregion


int main() {
    setlocale(LC_ALL, "ru");
    Num7();



    return 0;
}
