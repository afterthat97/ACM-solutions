#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#define maxv (55 * 55)
#define inf 0x3f3f3f3f
using namespace std;

typedef pair<int, int> P;

struct edge {
	int to, next, cap, cost;
}g[55 * 55 * 55 * 2];

int h[maxv], dis[maxv], prevv[maxv], preve[maxv], head[maxv];
int gsize, V, ST, ED, z[55][55], n, m;

inline void add_edge(int from, int to, int cap, int cost) {
    g[gsize] = {to, head[from], cap, cost};
    head[from] = gsize++;
	g[gsize] = {from, head[to], 0, -cost};
	head[to] = gsize++;
}

int min_cost_flow(int s, int t, int f) {
    int res = 0;
    memset(h, 0, sizeof h);
    while (f > 0) {
        priority_queue<P, vector<P>, greater<P> > que;
        memset(dis, 0x3f, sizeof dis);
        dis[s] = 0;
        que.push(P(0, s));
        while (!que.empty()) {
            P p = que.top(); que.pop();
            int v = p.second;
            if (dis[v] < p.first) continue;
            for (int i = head[v]; ~i; i = g[i].next)
                if (g[i].cap > 0 && dis[g[i].to] > dis[v] + g[i].cost + h[v] - h[g[i].to]) {
                    dis[g[i].to] = dis[v] + g[i].cost + h[v] - h[g[i].to];
                    prevv[g[i].to] = v;
                    preve[g[i].to] = i;
                    que.push(P(dis[g[i].to], g[i].to));
                }
        }
        if (dis[t] == inf) return -1;
        for (int v = 0; v < V; v++) h[v] += dis[v];
        int d = f;
        for (int v = t; v != s; v = prevv[v])
            d = min(d, g[preve[v]].cap);
        f -= d; res += d * h[t];
        for (int v = t; v != s; v = prevv[v]) {
            g[preve[v]].cap -= d;
            g[preve[v] ^ 1].cap += d;
        }
    }
    return res;
}

int main() {
    int T; cin >> T;
    while (T--) {
		gsize = 0;
        memset(h, 0, sizeof h);
        memset(prevv, 0, sizeof prevv);
        memset(preve, 0, sizeof preve);
		memset(head, -1, sizeof head);
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", &z[i][j]);
		int ST = n * m + n, ED = ST + 1; V = ED + 1;
		for (int i = 0; i < n; i++)
			add_edge(ST, i, 1, 0);
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				add_edge(n + i * n + j, ED, 1, 0);
				for (int k = 0; k < n; k++)
					add_edge(k, n + i * n + j, 1, (j + 1) * z[k][i]);
			}
        double ans = min_cost_flow(ST, ED, n);
		printf("%.6f\n", ans / n);
    }
    return 0;
}
