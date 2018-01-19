#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int n, w, a[105];

int main() {
	scanf("%d", &n);
	while (scanf("%d %d", &n, &w) == 2) {
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n);
		int ans = 0, sum = 0;
		for (; ans < n; ans++) {
			if (sum + a[ans] > w) break;
			sum += a[ans];
		}
		printf("%d\n", ans);
	}
	return 0;
}
