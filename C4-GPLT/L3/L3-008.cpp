#include <stdio.h>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int np, ne, k, g[10005][3];
typedef pair<int, int> node;

int bfs(int ps) {
	queue<node> q;
	q.push(node(ps, 0));
	int ans, maxl = -1;
	bool vis[10005] = {}; vis[ps] = 1;
	while (!q.empty()) {
		node now = q.front(); q.pop();
		if ((now.second > maxl)
			|| (now.second == maxl && now.first < ans)) {
			ans = now.first;
			maxl = now.second;
		}
		for (int i = 1; i <= g[now.first][0]; i++)
			if (!vis[g[now.first][i]]) {
				vis[g[now.first][i]] = 1;
				q.push(node(g[now.first][i], now.second + 1));
			}
	}
	if (maxl > 0) return ans; return 0;
}

int main() {
	scanf("%d %d %d", &np, &ne, &k);
	for (int i = 0; i < ne; i++) {
		int px, py;
		scanf("%d %d", &px, &py);
		g[px][++g[px][0]] = py;
		g[py][++g[py][0]] = px;
	}
	for (int i = 0; i < k; i++) {
		int ps; scanf("%d", &ps);
		printf("%d\n", bfs(ps));
	}
	return 0;
}
