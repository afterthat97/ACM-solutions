#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	puts("1000000 1000000 1000000");
	for (int i = 0; i < 1000000; i++)
		printf("%d ", rand() % 1000000 + 1);
	putchar('\n');
	for (int i = 0; i < 1000000; i++) {
		int l = rand() % 1000000 + 1;
		int r = rand() % 1000000 + 1;
		if (l > r) swap(l, r);
		printf("%d %d\n", l, r);
	}

	return 0;
}
