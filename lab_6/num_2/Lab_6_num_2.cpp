#include <iostream>
extern "C" double calc_asm(double x, double y);

double calc_c(double x, double y) {
	return x - y;
}




int main() {
	double x = 2.3;
	double y = 3.6;
	printf("c lang:\t\t%lf\n", calc_c(x, y));
	printf("asm lang:\t\t%lf", calc_asm(x, y));



	return 0;
}