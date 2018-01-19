#include <iostream>
#include <queue>
#include <stack>
#include <cstring>
#define fst first
#define snd second
#define INF 0x3f3f3f3f
using namespace std;

typedef pair<int, int> node;

char g[105][105];
int n, m, pre[105][105], steps[105][105];
stack<int> way;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0 ,1, 0, -1};
char dir[4] = {'D', 'R', 'U', 'L'};

bool valid(int x, int y) {
	if (x < 1 || x > n || y < 1 || y > m) return 0;
	if (g[x][y] == '*') return 0; else return 1;
}

node bfs() {
	queue<node> q;
	q.push(node(1, 1));
	while (!q.empty()) {
		node now = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = now.fst + dx[i], ny = now.snd + dy[i];
			if (valid(nx, ny) && steps[now.fst][now.snd] + 1 < steps[nx][ny]) {
				pre[nx][ny] = i;
				steps[nx][ny] = steps[now.fst][now.snd] + 1;
				q.push(node(nx, ny));
				if (g[nx][ny] == 'F') return node(nx, ny);
			}
		}
	}
}

int main() {
	int ps = 0, pe = 0;
	memset(steps, INF, sizeof steps); steps[1][1] = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> g[i][j];
	
	node cnt = bfs();
	while (cnt.fst != 1 || cnt.snd != 1) {
		int d = pre[cnt.fst][cnt.snd];
		way.push(d);
		cnt.fst -= dx[d]; cnt.snd -= dy[d];
	}

	int bx = 1, by = 1, px = 1, py = 1;
	while (!way.empty()) {
		int now = way.top(); way.pop();
		bx = px; by = py;
		printf("%c\n", dir[now]);
		fflush(stdout);
		scanf("%d %d", &px, &py);
		if (px == -1 || py == -1) return 0;
		if (bx == px && by == py) {
			if (now == 0 || now == 2) swap(dir[0], dir[2]);
			if (now == 1 || now == 3) swap(dir[1], dir[3]);
			way.push(now);
		}
	}	

	return 0;
}
