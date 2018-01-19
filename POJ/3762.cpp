#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#define maxv 5050
#define inf 0x3f3f3f3f
using namespace std;

typedef pair<int, int> P;

struct edge {
	int to, next, cap, cost;
}g[maxv << 2];

int h[maxv], dist[maxv], prevv[maxv], preve[maxv], head[maxv], gsize, V;
int a[maxv], b[maxv], w[maxv], idx[maxv], n, k, cnt;

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
        memset(dist, 0x3f, sizeof dist);
        dist[s] = 0;
        que.push(P(0, s));
        while (!que.empty()) {
            P p = que.top(); que.pop();
            int v = p.second;
            if (dist[v] < p.first) continue;
            for (int i = head[v]; ~i; i = g[i].next)
                if (g[i].cap > 0 && dist[g[i].to] > dist[v] + g[i].cost + h[v] - h[g[i].to]) {
                    dist[g[i].to] = dist[v] + g[i].cost + h[v] - h[g[i].to];
                    prevv[g[i].to] = v;
                    preve[g[i].to] = i;
                    que.push(P(dist[g[i].to], g[i].to));
                }
        }
        if (dist[t] == inf) return -1;
        for (int v = 0; v < V; v++) h[v] += dist[v];
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
    while (scanf("%d %d", &n, &k) == 2) {
		gsize = cnt = 0;
        memset(h, 0, sizeof h);
        memset(prevv, 0, sizeof prevv);
        memset(preve, 0, sizeof preve);
		memset(head, -1, sizeof head);
		for (int i = 0; i < n; i++) {
			int x1, y1, z1, x2, y2, z2;
			scanf("%d:%d:%d %d:%d:%d %d", &x1, &y1, &z1, &x2, &y2, &z2, &w[i]);
			a[i] = x1 * 60 * 60 + y1 * 60 + z1;
			b[i] = x2 * 60 * 60 + y2 * 60 + z2;
			idx[cnt++] = a[i]; idx[cnt++] = b[i];
		}
		sort(idx, idx + cnt);
		cnt = unique(idx, idx + cnt) - idx;
		int ST = cnt, ED = cnt + 1, ans = 0;
		add_edge(ST, 0, k, 0);
		add_edge(cnt - 1, ED, k, 0);
		for (int i = 0; i < cnt - 1; i++)
			add_edge(i, i + 1, inf, 0);
		for (int i = 0; i < n; i++) {
			a[i] = lower_bound(idx, idx + cnt, a[i]) - idx;
			b[i] = lower_bound(idx, idx + cnt, b[i]) - idx;
			add_edge(b[i], a[i], 1, w[i]);
			add_edge(ST, b[i], 1, 0);
			add_edge(a[i], ED, 1, 0);
			ans -= w[i];
		}
		V = cnt + 2;
		ans += min_cost_flow(ST, ED, k + n);
		printf("%d\n", -ans);
    }
    return 0;
}
