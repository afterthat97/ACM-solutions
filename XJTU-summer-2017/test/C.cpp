#include <iostream>
#include <stdio.h>
#include <cstring>
#include <queue>
#define inf 0x3f3f3f3f
using namespace std;

const int dx[6] = {1, -1, 0, 0, 0, 0};
const int dy[6] = {0, 0, 1, -1, 0, 0};
const int dz[6] = {0, 0, 0, 0, 1, -1};

struct node {
	int x, y, z, step;
	node(int xx, int yy, int zz) {
		x = xx; y = yy; z = zz;
	}
};

int n, m, l, p, g[105][105][105], steps[105][105][105];
node st(0, 0, 0), b(0, 0, 0), ed(0, 0, 0);

bool valid(int xx, int yy, int zz) {
	if (xx > 0 && yy > 0 && zz > 0
			&& xx <= n && yy <= m && zz <= l
			&& g[xx][yy][zz] == 0) return 1;
	return 0;
}

int bfs() {
	queue<node> q;
	steps[st.x][st.y][st.z] = 0;
	q.push(st); 
	while (!q.empty()) {
		node now = q.front(); q.pop();
		if (steps[now.x][now.y][now.z] < now.step) continue;
		if (now.x == ed.x && now.y == ed.y && now.z == ed.z) return now.step;
		for (int i = 0; i < 6; i++) {
			int nx = now.x + dx[i], ny = now.y + dy[i], nz = now.z + dz[i];
			if (valid(nx, ny, nz) && steps[nx][ny][nz] > now.step + 1) {
				node cnt(nx, ny, nz); 
				cnt.step = now.step + 1;
				steps[nx][ny][nz] = cnt.step;
				q.push(cnt);
			}
		}
	}
	return -1;
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		memset(g, 0, sizeof g);
		memset(steps, inf, sizeof steps);
		scanf("%d %d %d %d", &n, &m, &l, &p);
		for (int i = 0; i < p; i++) {
			scanf("%d %d %d", &b.x, &b.y, &b.z);
			g[b.x][b.y][b.z] = 1;
		}
		scanf("%d %d %d", &st.x, &st.y, &st.z);
		scanf("%d %d %d", &ed.x, &ed.y, &ed.z);
		if (g[ed.x][ed.y][ed.z]) { puts("-1"); continue; }
		printf("%d\n", bfs());
	}
	return 0;
}
