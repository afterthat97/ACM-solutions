#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	double s;
	while (scanf("%lf", &s) == 1 && s > 0.009) {
		int i;
		for (i = 2; s > 0; i++)
			s -= (double) 1 / i;
		printf("%d card(s)\n", i - 2);
	}
	return 0;
}
