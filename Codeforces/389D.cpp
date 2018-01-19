#include <iostream>
#include <stdio.h>
using namespace std;

int g[1005][1005], n;

int build(int st1, int st2, int ed, int k) {
	if (k == 1) {
		g[st1][ed] = g[st2][ed] = 1;
		return 0;
	}
	int n1 = ++n; int n2 = ++n;
	if (k & 1) {
		g[st1][n1] = g[st2][n1] = 1;
		g[st1][n2] = g[st2][n2] = 1;
		int mid = build(n1, n2, ed, (k - 1) / 2) + 1;
		for (int i = 0; i < mid; i++) {
			n1 = ++n; n2 = ++n;
			g[st1][n1] = g[st2][n2] = 1;
			st1 = n1; st2 = n2;
		}
		g[st1][ed] = g[st2][ed] = 1;
		return mid;
	} else {
		g[st1][n1] = g[st2][n1] = 1;
		g[st1][n2] = g[st2][n2] = 1;
		return build(n1, n2, ed, k / 2) + 1;
	}
}

int main() {
	int k; n = 2;
	scanf("%d", &k);
	build(1, 0, 2, k);
	printf("%d\n", n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			if (g[i][j] || g[j][i])
				putchar('Y');
			else
				putchar('N');
		putchar('\n');
	}
	return 0;
}
