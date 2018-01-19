#include <iostream>
#include <stdio.h>
using namespace std;

int eular (int x) {
	int ans = x;
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0) {
			while (x % i == 0) x /= i;
			ans /= i;
			ans *= (i - 1);
		}
	if (x != 1) { ans /= x; ans *= (x - 1); }
	return ans;
}

int main() {
	int n;
	while (scanf("%d", &n) == 1 && n)
		printf("%d\n", eular(n));
	return 0;
}
