#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <queue>
#define maxn 15
#define maxnp (150 * 150)
#define maxm (150 * 150 * 150)
#define fst first
#define snd second
#define inf 0x3f3f3f3f
using namespace std;

struct edge {
	int to, next;
}g[maxm];

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
typedef pair<int, int> point;
int gsize, np, nd, n, m;
int head[maxnp], match[maxnp], dis[maxn][maxn][maxn][maxn];
point door[maxnp], per[maxnp];
char ch[maxn][maxn];
bool vis[maxnp];

inline void add_edge(int from, int to) {
	g[gsize] = (edge){ to, head[from] };
	head[from] = gsize++;
}

bool dfs(int v) {
	if (vis[v]) return 0; else vis[v] = 1;
	for (int i = head[v]; ~i; i = g[i].next) {
		int t = g[i].to, w = match[t];
		if (w == -1 || dfs(w)) {
			match[v] = t; match[t] = v;
			return 1;
		}
	}
	return 0;
}

void bfs(int px, int py) {
	queue<point> q;
	q.push(point(px, py));
	dis[px][py][px][py] = 0;
	while (!q.empty()) {
		point now = q.front(); q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = now.fst + dx[k], ny = now.snd + dy[k];
			if (nx && ny && nx <= n && ny <= m) {
				if (dis[px][py][nx][ny] < inf || ch[nx][ny] != '.') continue;
				dis[px][py][nx][ny] = dis[px][py][now.fst][now.snd] + 1;
				q.push(point(nx, ny));
			}
		}		
	}
}

int main() {
	int T; cin >> T;
	while (T--) {
		memset(head, -1, sizeof head);
		memset(match, -1, sizeof match);
		memset(ch, 0, sizeof ch);
		memset(dis, 0x3f, sizeof dis);
		np = nd = gsize = 0;
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				cin >> ch[i][j];
				if (ch[i][j] == 'D')
					door[nd++] = point(i, j);
				if (ch[i][j] == '.')
					per[np++] = point(i, j);
			}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (ch[i][j] == 'D')
					bfs(i, j);
		for (int i = 0; i < nd; i++)
			for (int j = 0; j < np; j++)
				for (int k = dis[door[i].fst][door[i].snd][per[j].fst][per[j].snd];
						k <= n * m; k++)
					add_edge((k - 1) * nd + i, n * m * nd + j);
		int tot = 0;
		for (int i = 0; i < n * m * nd; i++)
			if (match[i] == -1) {
				memset(vis, 0, sizeof vis);
				if (dfs(i))
					if (++tot == np) {
						printf("%d\n", i / nd + 1);
						break;
					}
			}
		if (tot < np) puts("impossible");
		else if (np == 0) puts("0");
	}
	return 0;
}
