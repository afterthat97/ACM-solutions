#include <iostream>
#include <stdio.h>
#include <cstring>
#define maxn 1000005
using namespace std;

int f[maxn], t[maxn], p[maxn], n, m, flag[maxn];

void getf() {
	memset(f, -1, sizeof(int) * m);
	for (int i = 0, j = -1; i < m;) {
		while (~j && p[i] != p[j]) j = f[j];
		i++; j++;
		f[i] = p[i] == p[j] ? f[j] : j;
	}
}

void kmp(int dx) {
	for (int i = 0, j = 0; i < n;) {
		while (~j && t[i] != p[j] + dx) j = f[j];
		i++; j++;
		if (j == m) {
			flag[i - j] = 1;
			j = 0;
		}
	}
}

int main() {
	while (scanf("%d %d", &n, &m) == 2) {
		for (int i = 0; i < n; i++) scanf("%d", &t[i]);
		for (int i = 0; i < m; i++) scanf("%d", &p[i]);
		getf();
		int minn = 100, maxx = 0;
		for (int i = 0; i < m; i++) {
			minn = min(minn, p[i]);
			maxx = max(maxx, p[i]);
		}
		for (int dx = 1 - minn; dx <= 88 - maxx; dx++)
			kmp(dx);
		int ans = 0;
		for (int i = 0; i < n; i++)
			if (flag[i]) {
				ans++;
				i += m - 1;
			}
		printf("%d\n", ans);
		memset(flag, 0, sizeof(int) * n);
	}
	return 0;
}
