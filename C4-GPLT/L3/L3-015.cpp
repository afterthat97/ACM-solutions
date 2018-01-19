#include <iostream>
#include <stdio.h>
using namespace std;

int np, g[21][21], way[21];
bool succ, vis[21];

void dfs(int x, int k) {
	way[k] = x;
	if (k == np && g[x][1]) {
		succ = 1; return;
	} else if (k == 20) return;
	bool psb = 0;
	for (int i = 1; i <= np; i++)
		if (!vis[i] && g[i][1]) psb = 1;
	if (!psb) return;
	for (int i = 1; i <= np; i++)
		if (g[x][i] && !vis[i] && !succ) {
			vis[i] = 1;
			dfs(i, k + 1);
			vis[i] = 0;
		}
}

int main() {
	cin >> np;
	for (int i = 1; i <= np; i++)
		for (int j = 1; j <= np; j++) {
			char ch; cin >> ch;
			if (ch == 'W') g[i][j] = 1;
			if (ch == 'L') g[j][i] = 1;
		}
	vis[1] = 1;
	dfs(1, 1);
	if (!succ) { puts("No Solution"); return 0; }
	printf("%d", way[1]);
	for (int i = 2; i <= np; i++) printf(" %d", way[i]);
	return 0;
}
