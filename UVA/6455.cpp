#include <iostream>
#include <stdio.h>
#include <cstring>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;

struct point {
	int x, y;
	point(int x = 0, int y = 0):x(x), y(y) {};
}ps[5];

struct node {
	int x, y;
	int steps;
	node(int x, int y, int steps):x(x), y(y), steps(steps) {};
};

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };

int n, m, t, ans;
char map[105][105];
int steps[105][105], sp[5][5];

bool avail(int x, int y) {
	if (x >= 1 && y >= 1 && x <= n && y <= m && map[x][y] != '#') return 1;
	return 0;
}

void bfs(point p) {
	queue<node> q;
	q.push(node(p.x, p.y, 0));
	steps[p.x][p.y] = 1;

	while (!q.empty()) {
		node now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			if (avail(nx, ny) && !steps[nx][ny]) {
				steps[nx][ny] = now.steps + 1;
				q.push(node(nx, ny, now.steps + 1));
			}
		}
	}
}

bool used[5];

void dfs(int x, int num, int len) {
	used[x] = 1;
	if (num == t + 1) {
		if (len < ans) ans = len;
	}
	for (int i = 0; i <= t; i++)
		if (!used[i]) {
			used[i] = 1;
			dfs(i, num + 1, len + sp[x][i]);
			used[i] = 0;
		}
}

int main() {
	while (scanf("%d %d", &n, &m) == 2 && n && m) {
		ans = 0x3f3f3f3f;
		memset(map, 0, sizeof(map));
		memset(sp, 0, sizeof(sp));
		memset(ps, 0, sizeof(ps));
		memset(used, 0, sizeof(used));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				cin >> map[i][j];
				if (map[i][j] == '@') ps[0] = point(i, j);
			}
		cin >> t;
		for (int i = 1; i <= t; i++) {
			int a, b;
			cin >> a >> b;
			ps[i] = point(a, b);
		}
		for (int i = 0; i < t; i++) {
			memset(steps, 0, sizeof(steps));
			bfs(ps[i]);
			for (int j = i + 1; j <= t; j++)
				sp[i][j] = sp[j][i] = steps[ps[j].x][ps[j].y];
		}
		bool need = 1;
		for (int i = 1; i <= t; i++)
			if (sp[0][i] == 0) {
				cout << -1 << endl;
				need = 0;
			}
		if (!need) continue;
		dfs(0, 1, 0);
		cout << ans << endl;
	}

	return 0;
}