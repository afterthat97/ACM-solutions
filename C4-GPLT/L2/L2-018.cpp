#include <iostream>
#include <cmath>
#include <stdio.h>
#define maxn 1000005
using namespace std;

double a[maxn], b[maxn], ans[maxn];
int maxa, maxb, maxab;

void print(double *arr) {
	int len = 0;
	for (int i = 0; i < maxab; i++)
		if (fabs(arr[i]) >= 0.05) len++;
	if (len == 0) puts("0 0 0.0");
	else {
		printf("%d", len);
		for (int i = maxab; ~i; i--)
			if (fabs(arr[i]) >= 0.05)
				printf(" %d %.1lf", i, arr[i]);
		printf("\n");
	}
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int e, c; cin >> e >> c;
		maxa = max(maxa, e);
		a[e] = c;
	}
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int e, c; cin >> e >> c;
		maxb = max(maxb, e);
		b[e] = c;
	}
	maxab = max(maxa, maxb);
	while (maxa >= maxb) {
		double x = a[maxa] / b[maxb];
		ans[maxa - maxb] = x;
		for (int i = 0; i <= maxb; i++)
			a[i + maxa - maxb] -= b[i] * x;
		while (fabs(a[maxa]) < 1e-8) maxa--;
	}
	print(ans); print(a);
	return 0;
}
