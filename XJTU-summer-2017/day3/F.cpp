#include <iostream>
#include <stdio.h>
#include <cstring>
#include <queue>
using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

int px, py, a[7][7], que[30][2], cnt, area, add, ans = 100;
bool poss[7][7], vis[7][7];

typedef pair<int, int> node;

int bfs(int x, int y) {
	memset(vis, 0, sizeof vis);
	queue<node> q;
	q.push(node(x, y));
	vis[x][y] = 1;
	int ans = 1;
	while (!q.empty()) {
		node now = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if (nx > 0 && ny > 0 && nx < 6 && ny < 6)
				if (a[nx][ny] && !vis[nx][ny]) {
					vis[nx][ny] = 1; ans++;
					q.push(node(nx, ny));
				}
		}
	}
	return ans;
}

void dfs(int k) {
	if (k == cnt || add >= ans) return;
	int nx = que[k][0], ny = que[k][1];

	dfs(k + 1);
	
	if (area + add == bfs(px, py)) {
		if (add < ans) ans = add;
	}
	
	a[nx][ny] = 1; add++;
	
	if (area + add == bfs(px, py)) {
		if (add < ans) ans = add;
	}
	dfs(k + 1);
	a[nx][ny] = 0; add--;
}

int main() {
	for (int i = 1; i <= 5; i++)
		for (int j = 1; j <= 5; j++) {
			char ch; cin >> ch;
			a[i][j] = ch - '0';
			if (a[i][j]) { 
				area++; px = i; py = j; 
				for (int k = 1; k <= 5; k++) {
					poss[i][k] = 1;
					poss[k][j] = 1;
				}
			}
		}

	for (int i = 1; i <= 5; i++)
		for (int j = 1; j <= 5; j++)
			if (a[i][j] == 0 && poss[i][j] == 1) {
				que[cnt][0] = i; que[cnt++][1] = j;
			}
	dfs(0);
	cout << ans << endl;
	return 0;
}
