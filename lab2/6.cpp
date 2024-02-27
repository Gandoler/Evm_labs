#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;

void print64(void* p) {
    unsigned long long ull_value = *reinterpret_cast<unsigned long long*>(p);
    long long ll_value = *reinterpret_cast<long long*>(p);

    double double_value = *reinterpret_cast<double*>(p);

    printf("Значение беззнакового целого 64 бит: %llu\n", ull_value);
    printf("Значение знакового целого 64 бит: %lld\n", ll_value);

    printf("Значение с плавающей запятой (double) в фиксированной точке: %.2f\n", double_value);
    printf("Значение с плавающей запятой (double) в экспоненциальной записи: %.2e\n", double_value);
}


int main() {
   unsigned long long ull_val = 18446744073709551615ULL;
    long long ll_val = -922337203685LL;
    double double_val = 1234567890.123456789;


    print64(&ull_val);
    print64(&ll_val);
    print64(&double_val);

}
