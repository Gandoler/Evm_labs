#include <cstdio>
#include <iostream>
#include <iomanip>

void print16(const char* label, float value) {
    printf("%s: %hd\n", label, value);
}

void print32(const char* label, float value) {
    printf("%s: %d\n", label, value);
}

void print64(const char* label, double value) {
    printf("%s: %lld\n", label, value);
}

// Функция для вычисления частичной суммы гармонического ряда с "наивным" порядком
float naiveSum(int N) {
    float sum = 0.0f;
    for (int i = 1; i <= N; ++i) {
        sum += 1.0f / i;
    }
    return sum;
}

// Функция для вычисления частичной суммы гармонического ряда с обратным порядком
float reverseSum(int N) {
    float sum = 0.0f;
    for (int i = N; i >= 1; --i) {
        sum += 1.0f / i;
    }
    return sum;
}

int main() {
    // Значения N для проверки
    int N_values[] = {1000, 1000000/*, 1000000000*/};
    int num_N = sizeof(N_values) / sizeof(N_values[0]);

    for (int i = 0; i < num_N; ++i) {
        int N = N_values[i];
        float naive_result = naiveSum(N);
        float reverse_result = reverseSum(N);

        printf("N = %d\n", N);
        print16("Naive sum-16", naive_result);
        print16("Reverse sum-16", reverse_result);
        print32("Naive sum-32", naive_result);
        print32("Reverse sum-32", reverse_result);
        print64("Naive sum-64", naive_result);
        print64("Reverse sum-64", reverse_result);
        std::cout << "Naive sum: " << naive_result << std::endl;
        std::cout << "Reverse sum: " << reverse_result << std::endl;
        printf("\n");
    }

    return 0;
}
