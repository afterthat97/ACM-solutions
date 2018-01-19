#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <queue>
#define maxn 5050
#define maxm 50050
#define inf 0x3f3f3f3f
#define fst first
#define snd second
#define id(x, y) ((x - 1) * m + (y - 1))
#define rev(v) (v & 1 ? v - 1 : v + 1)
using namespace std;

struct edge {
    int to, next, cap;
}g[maxm << 1];

typedef pair<int, int> node;
int gsize, head[maxn];
bool used[maxn];
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

inline void add_edge(int from, int to, int cap) {
    g[gsize] = {to, head[from], cap};
    head[from] = gsize++;
    g[gsize] = {from, head[to], 0};
    head[to] = gsize++;
}

int n, m, stx, sty, tot, ch[100][100], vis[maxn];

int dfs(int v, int pe, int flow) {
	if (v == pe) return flow;
	used[v] = 1;
	for (int i = head[v]; ~i; i = g[i].next)
		if (!used[g[i].to] && g[i].cap > 0) {
			int d = dfs(g[i].to, pe, min(flow, g[i].cap));
			if (d > 0) {
				g[i].cap -= d;
				g[rev(i)].cap += d;
				return d;
			}
		}
	return 0;
}

int max_flow(int ps, int pe) {
	int ans = 0, f = 0;
	memset(used, 0, sizeof used);
	while (f = dfs(ps, pe, inf)) {
		memset(used, 0, sizeof used);
		ans += f;
	}
	return ans;
}

void bfs(int ps) {
	queue<int> q;
	q.push(ps); vis[ps] = 1;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int i = head[now]; ~i; i = g[i].next)
			if (!vis[g[i].to] && g[i].cap > 0) {
				vis[g[i].to] = 1;
				q.push(g[i].to);
			}
	}
	for (int i = 0; i < tot; i++)
		if (vis[i]) ch[i / m + 1][i % m + 1] = 2;
	memset(vis, 0, sizeof vis);
	for (int i = 0; i <= n + 1; i++)
		for (int j = 0; j <= m + 1; j++)
			if (ch[i][j] == 0) {
				queue<node> q;
				q.push(node(i, j)); ch[i][j] = -1;
				while (!q.empty()) {
					node now = q.front(); q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = now.fst + dx[k], ny = now.snd + dy[k];
						if (~nx && ~ny && nx <= n + 1 && ny <= m + 1) {
							if (ch[nx][ny] == 1 || ch[nx][ny] == -1) continue;
							if (ch[nx][ny] == 0) {
								ch[nx][ny] = -1;
								q.push(node(nx, ny));
							} else
								ch[nx][ny] = 1;
						}
					}
				}
			}
}

int main() {
	scanf("%d %d %d %d", &n, &m, &stx, &sty);
	memset(head, -1, sizeof head); tot = n * m;
	int pe = tot * 2 + 2;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			int w; scanf("%d", &w);
			if (i == stx && j == sty) w = inf;
			add_edge(id(i, j), id(i, j) + tot, w);
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k], ny = j + dy[k];
				if (nx && ny && nx <= n && ny <= m)
					add_edge(id(i, j) + tot, id(nx, ny), inf);
			}
			if (i == 1 || j == 1 || i == n || j == m)
				add_edge(id(i, j) + tot, pe, inf);
		}
	printf("%d\n", max_flow(id(stx, sty), pe));
	bfs(id(stx, sty));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			putchar(ch[i][j] == 1 ? 'X' : '.');
		putchar('\n');
	}
	return 0;
}
