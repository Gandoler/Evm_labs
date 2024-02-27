#include <iostream>
#include <iomanip>
#include <cstdint>

constexpr int N = 5;

template<typename T>
void printArray(const T* array, int length, const char* format) {
    for (int i = 0; i < length; ++i) {
        std::cout << std::setprecision(2) << std::scientific << std::setw(12) << std::setfill(' ') << std::right << std::noshowpos << std::fixed << format << array[i] << "\t";
    }
    std::cout << std::endl;
}

template<typename T>
void printIntArray(const T* array, int length, const char* format) {
    for (int i = 0; i < length; ++i) {
        std::cout << std::setw(12) << std::setfill(' ') << std::right << format << array[i] << "\t";
    }
    std::cout << std::endl;
}

int main() {
    std::uint16_t Ms[N] = {0xFADE, 0xFADE, 0xFADE, 0xFADE, 0xFADE};
    std::uint32_t Ml[N] = {0xADE1A1DA, 0xADE1A1DA, 0xADE1A1DA, 0xADE1A1DA, 0xADE1A1DA};
    std::int64_t Mq[N] = {0xC1A551F1AB1E, 0xC1A551F1AB1E, 0xC1A551F1AB1E, 0xC1A551F1AB1E, 0xC1A551F1AB1E};
    float Mfs[N] = {5.0f/3, 5.0f/3, 5.0f/3, 5.0f/3, 5.0f/3};
    double Mfl[N] = {5.0/3, 5.0/3, 5.0/3, 5.0/3, 5.0/3};

    std::cout << "Ms (uint16_t):" << std::endl;
    printIntArray(Ms, N, "%d\t");
    printIntArray(Ms, N, "%04hX\t");

    std::cout << "Ml (int32_t):" << std::endl;
    printIntArray(Ml, N, "%d\t");
    printIntArray(Ml, N, "%08X\t");

    std::cout << "Mq (int64_t):" << std::endl;
    printIntArray(Mq, N, "%lld\t");
    printIntArray(Mq, N, "%016llX\t");

    std::cout << "Mfs (float):" << std::endl;
    printArray(Mfs, N, "%.2f\t");
    printArray(Mfs, N, "%.2e\t");

    std::cout << "Mfl (double):" << std::endl;
    printArray(Mfl, N, "%.2lf\t");
    printArray(Mfl, N, "%.2le\t");

    return 0;
}
