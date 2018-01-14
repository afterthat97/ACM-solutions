#include <iostream>
#include <stdio.h>
using namespace std;

int a, b, c, n;

int main() {
	int idx = 1;
	while (scanf("%d %d %d %d", &a, &b, &c, &n) == 4 && a != -1) {
		a %= 23; b %= 28; c %= 33;
		for (int i = c;; i += 33)
			if (i % 23 == a && i % 28 == b && i - n > 0) {
				printf("Case %d: the next triple peak occurs in %d days.\n",
						idx++, i - n);
				break;
			}
	}
	return 0;
}
