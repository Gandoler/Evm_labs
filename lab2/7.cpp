#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;

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


int main() {
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
