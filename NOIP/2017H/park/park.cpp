#include <stdio.h>
#include <cstring>
#include <iostream>
#include <queue>
#define inf 0x3f3f3f3f
#define maxn 100050
#define maxm 400050
#define maxk 55
#define fst first
#define snd second
using namespace std;

int np, ne, gsize, K, MOD;
int head[maxn], sp1[maxn], sp2[maxn], deg[maxn], order[maxn], dp[maxn][maxk];
typedef pair<int, int> node;

struct edge {
    int to, cost, next;
    edge(int t = 0, int c = 0, int n = 0): 
		to(t), cost(c), next(n) {}
}g[maxm];

inline void add_edge(int px, int py, int d) {
    g[gsize] = edge(py, d, head[px]);
    head[px] = gsize++;
}

void dijkstra(int ps, int *sp) {
    priority_queue<node, vector<node>, greater<node> > q;
    memset(sp, inf, sizeof(int) * maxn); sp[ps] = 0;
    q.push(node(0, ps));
    while (!q.empty()) {
		node p = q.top(); q.pop();
		if (sp[p.snd] < p.fst) continue;
		for (int cnt = p.snd, i = head[p.snd]; ~i; i = g[i].next) 
			if (sp[g[i].to] > sp[cnt] + g[i].cost) {
				sp[g[i].to] = sp[cnt] + g[i].cost;
				q.push(node(sp[g[i].to], g[i].to));
			}
    }
}

int topologic() {
	int cnt = 0;
	for (int now = 1; now <= np; now++)
		for (int i = head[now]; ~i; i = g[i].next)
			if (sp1[now] + g[i].cost == sp1[g[i].to])
				deg[g[i].to]++;
	for (int i = 1; i <= np; i++)
		if (deg[i] == 0) order[cnt++] = i;
	for (int j = 0; j < cnt; j++) {
		int now = order[j];
		for (int i = head[now]; ~i; i = g[i].next)
			if (sp1[now] + g[i].cost == sp1[g[i].to])
				if ((--deg[g[i].to]) == 0) 
					order[cnt++] = g[i].to;
	}
	for (int i = 1; i <= np; i++)
		if (deg[i] && sp1[i] + sp2[i] <= sp1[np] + K)
			return -1;
	return cnt;
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		memset(head, -1, sizeof head);
		memset(dp, 0, sizeof dp);
		memset(deg, 0, sizeof deg);
		gsize = 0; dp[1][0] = 1;
		scanf("%d %d %d %d", &np, &ne, &K, &MOD);
		for (int i = 0; i < ne; i++) {
			int px, py, w;
			scanf("%d %d %d", &px, &py, &w);
			add_edge(px, py, w);
		}
		dijkstra(1, sp1);
		dijkstra(np, sp2);
		int tot = topologic();
		if (tot == -1) { puts("-1"); continue; }
		for (int k = 0; k <= K; k++)
			for (int j = 0; j < tot; j++) {
				int now = order[j];
				for (int i = head[now]; ~i; i = g[i].next) {
					int k2 = k + sp1[now] + g[i].cost - sp1[g[i].to];
					if (k2 <= K)
						dp[g[i].to][k2] = (dp[g[i].to][k2] + dp[now][k]) % MOD;
				}
			}
		int ans = 0;
		for (int k = 0; k <= K; k++)
			ans = (ans + dp[np][k]) % MOD;
		printf("%d\n", ans);
	}
	return 0;
}
