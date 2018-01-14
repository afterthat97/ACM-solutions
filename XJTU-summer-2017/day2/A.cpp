#include <iostream>
#include <stdio.h>
using namespace std;

int n, a, sum, ans;

int main() {
	while (scanf("%d", &n) == 1) {
		sum = 0; ans = -0x3f3f3f3f;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a);
			sum += a;
			if (sum > ans) ans = sum;
			if (sum < 0) sum = 0;
		}
		printf("%d\n", ans);
	}
	return 0;
}
