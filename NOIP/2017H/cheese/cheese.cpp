#include <iostream>
#include <stdio.h>
#include <queue>
#include <cstring>
#define maxn 1005
using namespace std;

struct point {
	double x, y, z;
}p[maxn];

int n, g[maxn][maxn];
double h, r;

double dis(const point& p1, const point& p2) {
	double dx = p1.x - p2.x, dy = p1.y - p2.y, dz = p1.z - p2.z;
	return dx * dx + dy * dy + dz * dz;
}

int bfs(int ps) {
	int vis[maxn] = {};
	queue<int> q;
	q.push(ps); vis[ps] = 1;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		if (p[now].z + r >= h) return 1;
		for (int i = 0; i < n; i++)
			if (g[now][i] && !vis[i]) {
				vis[i] = 1; q.push(i);
			}
	}
	return 0;
}

int main() {
	int T; cin >> T;
	while (T--) {
		cin >> n >> h >> r;
		memset(g, 0, sizeof g);
		for (int i = 0; i < n; i++)
			cin >> p[i].x >> p[i].y >> p[i].z;
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				if (dis(p[i], p[j]) <= 4 * r * r)
					g[i][j] = g[j][i] = 1;
		int ans = 0;
		for (int i = 0; i < n; i++)
			if (p[i].z <= r)
				ans = max(ans, bfs(i));
		puts(ans ? "Yes" : "No");
	}
	return 0;
}
