#include <stdio.h>
#include <iostream>
using namespace std;
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

int main() {
    int num = 42;
    viewPointer(&num);  
}
