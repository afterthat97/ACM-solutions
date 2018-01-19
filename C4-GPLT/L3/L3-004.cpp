#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <queue>
using namespace std;

const int dx[6] = { 1, -1, 0, 0, 0, 0 };
const int dy[6] = { 0, 0, 1, -1, 0, 0 };
const int dz[6] = { 0, 0, 0, 0, 1, -1 };
int  a[1300][130][65];
int x, y, z, w;

struct node {
	int x, y, z;
	node(int x, int y, int z): x(x), y(y), z(z) {}
};

inline bool valid(int a, int b, int c) {
	if (a == 0 || b == 0 || c == 0) return 0;
	if (a > x || b > y || c > z) return 0; else return 1;
}

int bfs(const node& s) {
	queue<node> q;
	q.push(s); a[s.x][s.y][s.z] = 0;
	int cnt = 1;
	while (!q.empty()) {
		node now = q.front(); q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = now.x + dx[i], ny = now.y + dy[i], nz = now.z + dz[i];
			if (!valid(nx, ny, nz) || !a[nx][ny][nz]) continue;
			q.push(node(nx, ny, nz)); a[nx][ny][nz] = 0; cnt++;
		}
	}
	if (cnt < w) cnt = 0;
	return cnt;
}

int main() {
	scanf("%d %d %d %d", &x, &y, &z, &w);
	for (int k = 1; k <= z; k++)
		for (int i = 1; i <= x; i++)
			for (int j = 1; j <= y; j++)
				scanf("%d", &a[i][j][k]);

	int ans = 0;
	for (int i = 1; i <= x; i++)
		for (int j = 1; j <= y; j++)
			for (int k = 1; k <= z; k++)
				if (a[i][j][k]) ans += bfs(node(i, j, k));
	printf("%d", ans);
	return 0;
}
