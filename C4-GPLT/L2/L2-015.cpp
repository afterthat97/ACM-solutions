#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <stdlib.h>
using namespace std;

double g[10005];

bool cmp(double a, double b) {
	return a > b;
}

int main() {
	int n, m, k;
	cin >> n >> k >> m;
	for (int i = 0; i < n; i++) {
		int maxv = -1, minv = 101, ansv = 0;
		for (int j = 0; j < k; j++) {
			int v; scanf("%d", &v);
			maxv = max(maxv, v);
			minv = min(minv, v);
			ansv += v;
		}
		ansv -= (maxv + minv);
		g[i] = (ansv * 1.0) / (k - 2);
	}

	sort(g, g + n, cmp);

	printf("%.3lf", g[m - 1]);
	for (int i = m - 2; ~i; i--) printf(" %.3lf", g[i]);
	return 0;
}
