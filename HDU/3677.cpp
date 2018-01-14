#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
const double eps = 1e-8;
using namespace std;

int v[8], l, T, n;
bool used[8], link[8][8];
double ans;

void cmp(const int& a, const int& b) {
	if (v[a] * l + v[a] * v[b] * T < v[b] * l)//no: a->b
		link[a][b] = 0;
	if (v[b] * l + v[a] * v[b] * T < v[a] * l)//no: b->a
		link[b][a] = 0;
}

void dfs(int x, int count) {
	used[x] = 1;
	if (count == n) {
		double all = (n - 1)*T + ((l*1.0) / v[x]);
		if (all < ans) ans = all;
		return;
	}
	for (int i = 0; i<n; i++)
		if (!used[i] && link[x][i]) {
			used[i] = 1;
			dfs(i, count + 1);
			used[i] = 0;
		}
}

int main() {
	int idx = 0;
	while (scanf("%d %d %d", &l, &n, &T) == 3 && l > 0) {
		ans = 999999999;
		idx++;
		for (int i = 0; i<n; i++) scanf("%d", &v[i]);
		for (int i = 0; i<n; i++)
			for (int j = 0; j<n; j++)
				link[i][j] = 1;
		for (int i = 0; i<n - 1; i++)
			for (int j = i + 1; j<n; j++)
				cmp(i, j);
		for (int i = 0; i<n; i++) {
			memset(used, 0, sizeof(used));
			dfs(i, 1);
		}
		printf("Case %d: %d\n", idx, int(ans + eps + 0.5));
	}
	return 0;
}
