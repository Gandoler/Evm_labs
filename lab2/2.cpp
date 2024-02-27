#include <stdio.h>

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


int main() {
    long long value1 = 0x1122334455667788LL;
    PrintPointer(&value1);
    char value2[] = "0123456789abcdef";
    PrintPointer(&value2);
}
