#include <stdio.h>
#include <stdlib.h>

int n, m, cnt, num[105], ans[105];

void print() {
	printf("%d", ans[0]);
	for (int i = 1; i < cnt; i++) printf(" %d", ans[i]);
	exit(0);
}

void dfs(int x, int w) {
	if (w == 0) print();
	if (x > w) return;
	for (int i = num[x]; i >= 0; i--)
		if (w >= i * x) {
			for (int j = 0; j < i; j++) ans[cnt++] = x;
			dfs(x + 1, w - i * x);
			cnt -= i;
		}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int v; scanf("%d", &v);
		if (v <= m) num[v]++;
	}
	dfs(1, m);
	puts("No Solution");
	return 0;
}
