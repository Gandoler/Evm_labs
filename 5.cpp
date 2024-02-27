#include <iostream>
#include <iomanip>
#include <cstdint>

const int N = 5;

int main() {
    uint16_t Ms[N] = {0xFADE, 0xFADE, 0xFADE, 0xFADE, 0xFADE};

    // Вывод адресов элементов массива
    printf("Address of the beginning of the array M: %p\n", (void*)Ms);
    printf("Address of the first element of the array M: %p\n", (void*)&Ms[0]);
    printf("Address of the second element of the array M: %p\n", (void*)&Ms[1]);

    // Сравнение адресов
    printf("\nComparison of addresses:\n");
    printf("Address of the first element minus address of the beginning: %td\n", (intptr_t)(&Ms[0]) - (intptr_t)(Ms));
    printf("Address of the second element minus address of the beginning: %td\n", (intptr_t)(&Ms[1]) - (intptr_t)(Ms));

    // Сравнение с размером элемента массива
    printf("\nComparison with the size of array element:\n");
    printf("Size of array element: %zu\n", sizeof(Ms[0]));
    printf("Address of the second element minus address of the first element: %td\n", (intptr_t)(&Ms[1]) - (intptr_t)(&Ms[0]));

    return 0;
}