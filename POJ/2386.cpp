#include <iostream>
#include <stdio.h>
#include <queue>
#define fst first
#define snd second
using namespace std;

const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
int n, m, vis[105][105];
char ch[105][105];
typedef pair<int, int> point;

int bfs(int px, int py) {
	queue<point> q;
	q.push(point(px, py));
	vis[px][py] = 1;
	while (!q.empty()) {
		point now = q.front(); q.pop();
		for (int k = 0; k < 8; k++) {
			int nx = now.fst + dx[k];
			int ny = now.snd + dy[k];
			if (nx && ny && nx <= n && ny <= m) {
				if (vis[nx][ny] || ch[nx][ny] != 'W') continue;
				vis[nx][ny] = 1;
				q.push(point(nx, ny));
			}
		}
	}
	return 1;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> ch[i][j];
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (ch[i][j] == 'W' && !vis[i][j])
				ans += bfs(i, j);
	cout << ans << endl;
	return 0;
}
