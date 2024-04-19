#include <iostream>
using namespace std;


int main()
{
    int i=0, start=1, mull=2;
    cin >> i;

    int N = i + 2;
    int * intArray = new int [N];
    for(int i=0;i<N;i++)
        {
            intArray[i] = 0;
        }
    i=i+1;
    asm(
        "movl $1, %%ebx\n\t"
        "movl $0, %%eax\n"
        "movl %[intArray], %%ecx\n\t"
        "movl %%eax,(%%ecx, %%ebx, 4)\n\t"
        "movl $2, %%ebx\n\t"
        "movl $1, %%eax\n"
        "movl %[intArray], %%ecx\n\t"
        "movl %%eax,(%%ecx, %%ebx, 4)\n\t"
        "start: \n"
        "cmpl %[i], %%ebx\n\t"
        "jg   end\n"
        "movl (%%ecx, %%ebx, 4),%%eax\n\t"
        "imull %[f2],%%eax\n"
        "movl %[intArray], %%ecx\n\t"
        "incl %%ebx\n\t"
        "movl %%eax,(%%ecx, %%ebx, 4)\n\t"
        "jmp start\n"
        "end: \n"
        :[f2]"+r"(mull),[i]"+r"(i)
        :[intArray]"m"(intArray)
        :"%eax","%ecx","%ebx","memory"
    );
    
    for(int i=1;i<N;i++)
        {
            cout << intArray[i]<< "," ;
        }
    return 0;
}
