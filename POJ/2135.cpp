#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#define maxv 5050
#define maxm 20050
#define inf 0x3f3f3f3f
using namespace std;

typedef pair<int, int> P;

struct edge {
	int to, next, cap, cost;
}g[maxm << 1];

int h[maxv], dist[maxv], prevv[maxv], preve[maxv], head[maxv], val[maxv];
int gsize, V, np, ne, ST, ED;

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
    while (scanf("%d %d", &np, &ne) == 2) {
		gsize = 0;
        memset(h, 0, sizeof h);
        memset(prevv, 0, sizeof prevv);
        memset(preve, 0, sizeof preve);
		memset(head, -1, sizeof head);
        for (int i = 0; i < ne; i++) {
			int px, py, w;
			scanf("%d %d %d", &px, &py, &w);
			add_edge(px - 1, py - 1, 1, w);
			add_edge(py - 1, px - 1, 1, w);
        }
        V = np;
        cout << min_cost_flow(0, np - 1, 2) << endl;
    }
    return 0;
}
