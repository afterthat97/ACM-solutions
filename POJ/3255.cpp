#include <stdio.h>
#include <cstring>
#include <iostream>
#include <queue>
#define inf 0x3f3f3f3f
#define maxn 10005
#define maxm 200005
#define fst first
#define snd second
using namespace std;

int np, ne, gsize, head[maxn], sp[maxn], sp2[maxn];

typedef pair<int, int> node;
struct edge {
    int to, cost, next;
}g[maxm];

inline void add_edge(int px, int py, int d) {
    g[gsize] = (edge) { py, d, head[px] };
    head[px] = gsize++;
}

void dijkstra(int ps) {
    priority_queue<node, vector<node>, greater<node> > q;
    memset(sp, inf, sizeof sp);
	memset(sp2, inf, sizeof sp2);
	sp[ps] = 0;
    q.push(node(0, ps));
    while (!q.empty()) {
		node p = q.top(); q.pop();
		if (sp2[p.snd] < p.fst) continue;
		for (int cnt = p.snd, i = head[p.snd]; ~i; i = g[i].next) {
			int dis = sp[cnt] + g[i].cost;
			int dis2 = sp2[cnt] + g[i].cost; // dis <= dis2
			if (sp[g[i].to] > dis) {
				sp[g[i].to] = dis;
				q.push(node(sp[g[i].to], g[i].to));
			}
			if (sp[g[i].to] < dis && sp2[g[i].to] > dis) {
				sp2[g[i].to] = dis;
				q.push(node(sp2[g[i].to], g[i].to));
			} else if (sp2[g[i].to] > dis2) {
				sp2[g[i].to] = dis2;
				q.push(node(sp2[g[i].to], g[i].to));
			}
		}
    }
}

int main() {
    memset(head, -1, sizeof head);
	scanf("%d %d", &np, &ne);
	for (int i = 0; i < ne; i++) {
		int px, py, w;
		scanf("%d %d %d", &px, &py, &w);
		add_edge(px, py, w);
		add_edge(py, px, w);
	}
	dijkstra(1);
	cout << sp2[np] << endl;
	return 0;
}
