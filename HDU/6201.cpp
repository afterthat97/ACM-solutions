#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#define maxvv 500050
#define inf 0x3f3f3f3f
#define rev(v) (v & 1 ? v - 1 : v + 1)
using namespace std;

typedef pair<int, int> P;

struct edge {
    int to, next, cap, cost;
}g[maxvv << 1];

int gsize, V, h[maxvv], dist[maxvv], prevv[maxvv], preve[maxvv], head[maxvv];

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
        f -= d;
        res += d * h[t];
        for (int v = t; v != s; v = prevv[v]) {
            g[preve[v]].cap -= d;
            g[rev(preve[v])].cap += d;
        }
    }
    return res;
}

int val[maxvv];

int main() {
    int T; cin >> T;
    while (T--) {
        gsize = 0;
        memset(h, 0, sizeof h);
        memset(prevv, 0, sizeof prevv);
        memset(preve, 0, sizeof preve);
        memset(head, -1, sizeof head);
        int np, ne;
        scanf("%d", &np); ne = np - 1;
        for (int i = 1; i <= np; i++)
            scanf("%d", &val[i]);
        for (int i = 0; i < ne; i++) {
            int px, py, w;
            scanf("%d %d %d", &px, &py, &w);
            add_edge(px, py, 1, w);
            add_edge(py, px, 1, w);
        }
        int ST = 0, ED = np + 1;
        for (int i = 1; i <= np; i++) {
            add_edge(ST, i, 1, val[i]);
            add_edge(i, ED, 1, 10000 - val[i]);
        }
        V = ED + 1;
        cout << 10000 - min_cost_flow(ST, ED, 1) << endl;
    }
    return 0;
}
