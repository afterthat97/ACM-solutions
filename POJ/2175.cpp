#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#define maxn 550
#define maxm 50050
#define inf 0x3f3f3f3f
using namespace std;

typedef pair<int, int> P;

struct edge {
	int to, next, cap, cost;
}g[maxm << 1];

struct node {
	int x, y, w;
}bld[maxn], des[maxn];

int h[maxn], dis[maxn], prevv[maxn], preve[maxn], head[maxn];
int gsize, V, ST, ED;

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
	int n, m;
    while (scanf("%d %d", &n, &m) == 2) {
		gsize = 0;
        memset(h, 0, sizeof h);
        memset(prevv, 0, sizeof prevv);
        memset(preve, 0, sizeof preve);
		memset(head, -1, sizeof head);
		int totflow = 0, totcost = 0;
		for (int i = 0; i < n; i++) {
			int x, y, w;
			scanf("%d %d %d", &x, &y, &w);
			bld[i] = (node){ x, y, w };
			totflow += w;
		}
		for (int i = 0; i < m; i++) {
			int x, y, w;
			scanf("%d %d %d", &x, &y, &w);
			des[i] = (node){ x, y, w };
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int t; scanf("%d", &t);
				int dis = abs(bld[i].x - des[j].x) + abs(bld[i].y - des[j].y) + 1;
				totcost += dis * t;
			}
			for (int j = m - 1; ~j; j--) {
				int dis = abs(bld[i].x - des[j].x) + abs(bld[i].y - des[j].y) + 1;
				add_edge(i, n + j, inf, dis);
			}
		}
		ST = n + m; ED = n + m + 1; V = n + m + 2;
		for (int i = 0; i < n; i++)
			add_edge(ST, i, bld[i].w, 0);
		for (int i = 0; i < m; i++)
			add_edge(n + i, ED, des[i].w, 0);
        int ans = min_cost_flow(ST, ED, totflow);
		if (ans < totcost) {
			puts("SUBOPTIMAL");
			for (int i = 0; i < n; i++)
				for (int j = g[head[i]].next; ~j; j = g[j].next)
					printf("%d%c", g[j ^ 1].cap, ~g[j].next ? ' ' : '\n');
		} else
			puts("OPTIMAL");
    }
    return 0;
}
