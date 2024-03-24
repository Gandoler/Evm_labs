#include <stdio.h>
#include <stdint.h>

void calculate(long int x, long int y, long int *z, long int *w);

int main() {
    long int x = 10;
    long int y = 5;
    long int z=0, w=0;

    calculate(x, y, &z, &w);

    printf("x = %ld\n", x);
    printf("y = %ld\n", y);
    printf("z = %ld\n", z);
    printf("w = %ld\n", w);

    return 0;
}

void calculate(long int x, long int y, long int *z, long int *w) {
    asm volatile (
        "addq %[y], %[x]\n\t"  // Вычисляем z = x + y
        "movq %[x], %[z]\n\t"  // Сохраняем результат в z
        "subq %[y], %[x]\n\t"  // Вычисляем w = x - y
        "movq %[x], %[w]\n\t"  // Сохраняем результат в w
        : [z] "=r" (*z), [w] "=r" (*w)
        : [x] "r" (x), [y] "r" (y) // Именованные операнды
        : "cc"  // Флаги состояния изменяются
    );
}
