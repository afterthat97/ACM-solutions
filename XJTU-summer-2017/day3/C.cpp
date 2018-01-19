#include <iostream>
#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;

struct node {
	int a[3], step;
	node(int s, int n, int m, int st) {
		a[0] = s; a[1] = n; a[2] = m; step = st;
	}
};

int aa[3];
bool vis[101][101][101];

void bfs() {
	queue<node> q;
	q.push(node(aa[0], 0, 0, 0));
	vis[aa[0]][0][0] = 1;
	while (!q.empty()) {
		node now = q.front(); q.pop();
		if (now.a[0] == aa[0] / 2)
			if (now.a[1] == 0 || now.a[2] == 0) {
				printf("%d\n", now.step); return;
			}
		node cnt = now;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (i != j) {// i -> j
					cnt = now;
					if (now.a[i] > aa[j] - now.a[j]) {
						cnt.a[i] -= aa[j] - now.a[j];
						cnt.a[j] = aa[j];
					} else {
						cnt.a[j] += now.a[i];
						cnt.a[i] = 0;
					}
					if (!vis[cnt.a[0]][cnt.a[1]][cnt.a[2]]) {
						cnt.step = now.step + 1;
						vis[cnt.a[0]][cnt.a[1]][cnt.a[2]] = 1;
						q.push(cnt);
					}
				}
	}
	puts("NO");
}

int main() {
	while (scanf("%d %d %d", &aa[0], &aa[1], &aa[2]) == 3 && aa[0]) {
		if (aa[0] & 1) { puts("NO"); continue; }
		memset(vis, 0, sizeof vis);
		bfs();
	}
	return 0;
}
