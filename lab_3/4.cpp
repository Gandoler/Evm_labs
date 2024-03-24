#include <iostream>
#include <cstdint>

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
    int m = 231, n = -33;
    int min_signed = INT32_MIN;
    unsigned int max_unsigned = UINT32_MAX;
    int max_signed = INT32_MAX;
    float a = 0.0f, b = 1.0f, c = 12345678.0f, d = 123456789.0f;

    printf("\t\tbefore\t int\n");
    printf("signed int32 = 231 after:\t%d\n",m);
    printf("signed int32 = -33 after:\t%d\n",n);
    printf("signed int32 = minimal after:\t%d\n",min_signed);
    printf("signed int32 = maximum after:\t%d\n",INT32_MAX);
    printf("unsigned int32 = max unsigned after:\t%u\n",max_unsigned);
    printf("\t\tafter\n###################################\n");
    ++m;
    ++n;
    ++max_unsigned;
    ++min_signed;
    ++max_signed;
    printf("signed int32 = 231 after:\t%d\n",m);
    printf("signed int32 = -33 after:\t%d\n",n);
    printf("signed int32 = minimal after:\t%d\n",min_signed);
    printf("signed int32 = maximum after:\t%d\n",INT32_MAX);
    printf("unsigned int32 = max unsigned after:\t%u\n",max_unsigned);
    ////////////////////////////////////////////////////
    max_signed = max_signed+123;
    printf("\n\nunsigned int32 = max unsigned after:\t%u\n\n\n\n",max_unsigned);
    ////////////////////////////////////////////////////
    ////////////////////////////////////////////////////
    ////////////////////////////////////////////////////
    printf("\t\tbefore\t float\n");
    printf("signed int32 = 0.0f after:\n");
    print32(reinterpret_cast<int*>(&a));
    printf("signed int32 = 1.0f after:\n");
    print32(reinterpret_cast<int*>(&b));
    printf("signed int32 = 12345678.0f after:\n");
    print32(reinterpret_cast<int*>(&c));
    printf("signed int32 = 123456789.0f after:\n");
    print32(reinterpret_cast<int*>(&d));

    printf("\t\tafter\n###################################\n");
    ++*reinterpret_cast<int*>(&a);
    ++*reinterpret_cast<int*>(&b);
    ++*reinterpret_cast<int*>(&c);
    ++*reinterpret_cast<int*>(&d);
    printf("signed int32 = 0.0f after:\t%d\n");
    print32(reinterpret_cast<int*>(&a));
    printf("signed int32 = 1.0f after:\t%d\n");
    print32(reinterpret_cast<int*>(&b));
    printf("signed int32 = 12345678.0f after:\t%d\n");
    print32(reinterpret_cast<int*>(&c));
    printf("signed int32 = 123456789.0f after:\t%d\n");
    print32(reinterpret_cast<int*>(&d));

    return 0;
}
