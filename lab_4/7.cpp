#include <iostream>
using namespace std;


int main() {
    float mas_32[5] = {0.0};
    double mas_64[5] = {0.0}; 
    cout << "до изменения\n";
    for(int i = 0;i < size(mas_32); i++){
        printf("%.12f\t", mas_32[i]);  
    }
    cout << "\n";
    for(int i = 0;i < size(mas_32); i++){
        printf("%.12lf\t", mas_64[i]);  
    }
    int i = 3;
    float insert_f = 3.123123f;
    double insert_d = 3.123123123213;

    //вставим все переменные в массивы своих типов
    asm(
        "movss %[insert_f], %%xmm0\n\t"//float в xmm0
        "movsd %[insert_d], %%xmm1\n\t"
        "leaq (%[mas_32], %%rax, 4), %[mas_32]\n\t"
        "leaq (%[mas_64], %%rax, 8), %[mas_64]\n\t"
        "movss %%xmm0, (%[mas_32])\n\t"
        "movsd %%xmm1, (%[mas_64])\n\t"
        :
        :"r"(i),[mas_32] "r"(mas_32),
        [insert_f]"m"(insert_f), [insert_d]"m"(insert_d), 
        [mas_64] "r"(mas_64)
        :"xmm0"
    );
     cout << "\nпосле\n";
    for(int i = 0;i < size(mas_32); i++){
        printf("%.12f\t", mas_32[i]);  
    }
    cout << "\n";
    for(int i = 0;i < size(mas_32); i++){
        printf("%.12lf\t", mas_64[i]);  
    }
    return 0;
}
