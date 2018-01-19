#include <iostream>
#include <stdio.h>
using namespace std;

int jo[15], x;

void init() {
	for (int k = 1; k < 14; k++) {
		int n = k * 2, m = 1, ans[30] = {};
		for (int i = 1; i <= k; i++) {
			ans[i] = (ans[i - 1] + m - 1) % (n - i + 1);
			if (ans[i] < k) { i = 0; m++; }
		}
		jo[k] = m;
	}
}

int main() {
	init();
	while (scanf("%d", &x) == 1 && x)
		printf("%d\n", jo[x]);
	return 0;
}
