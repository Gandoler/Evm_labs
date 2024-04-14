#include <iostream>
extern "C" {
    int print_seven_and_return_2(int param1, int param2, int param3, int param4, int param5, int param6, int param7);
}
int print_seven_and_return_2(int param1, int param2, int param3, int param4, int param5, int param6, int param7);
int print_seven_and_return_2(int param1, int param2, int param3, int param4, int param5, int param6, int param7) {
    printf("Parameters: %d %d %d %d %d %d %d\n", param1, param2, param3, param4, param5, param6, param7);
    return param2;
}