#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main() {
	int cho, x1, x2, y1, y2;
	while (scanf("%d %d %d %d %d", &cho, &x1, &y1, &x2, &y2) == 5) {
		if (cho == 1) {
			printf("%d\n", (abs(x2 - x1) > 0) + (abs(y2 - y1) > 0));
		} else if (cho == 2) {
			int k1 = abs(x1 + y1 - x2 - y2);
			int k2 = abs(x1 - y1 - x2 + y2);
			if (k1 & 1)
				puts("-1");
			else
				printf("%d\n", (k1 / 2 > 0) + (k2 / 2 > 0));
		} else {
			int k1 = abs(x1 + y1 - x2 - y2);
			int k2 = abs(x1 - y1 - x2 + y2);
			if (k1 == 0 || k2 == 0 || x1 == x2 || y1 == y2) 
				puts("1");
			else 
				puts("2");
		}
	}
	return 0;
}
