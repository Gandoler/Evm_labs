// Type your code here, or load an example.
 #include <iostream>
 using namespace std;

 #define PRINT_SIZE(type) printf("Размер " #type ": %zu байт\n", sizeof(type))

int main() {
    // Вывод размеров переменных
    PRINT_SIZE(char);
    PRINT_SIZE(signed char);
    PRINT_SIZE(unsigned char);
    PRINT_SIZE(char*);
    PRINT_SIZE(bool);
    PRINT_SIZE(wchar_t);
    PRINT_SIZE(short);
    PRINT_SIZE(int);
    PRINT_SIZE(long);
    PRINT_SIZE(long long);
    PRINT_SIZE(float);
    PRINT_SIZE(double);
    PRINT_SIZE(long double);
    PRINT_SIZE(size_t);
    PRINT_SIZE(ptrdiff_t);
    PRINT_SIZE(void*);

    return 0;
 }