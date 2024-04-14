#include <iostream>
extern "C" int calculate_asm(int x, int y);

int calculate_c(int x, int y) {
    int z = -113 + x + 2 * y;
    return z;
}

int main() {
    int x = 5;
    int y = 10;
    int z;

    z = calculate_asm(x, y);
    printf("Result (asm) = %d\n", z);

    z = calculate_c(x, y);
    printf("Result (cpp) = %d\n", z);

    return 0;
}
