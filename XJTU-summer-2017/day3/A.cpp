#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <queue>
#define maxn 1005
#define maxm (maxn * maxn)
#define inf 0x3f3f3f3f
#define fst first
#define snd second
using namespace std;

bool notp[maxn];
int prime[maxn], pnum, id[maxn];

void sieve(int x) {//NloglogN ~= N
	pnum = 0;
	for (int i = 2; i < x; i++)
		if (!notp[i]) {
			if (i > 99)  { prime[pnum] = i; id[i] = pnum++; }
			for (int j = 2; i * j < x; j++)
				notp[i * j] = 1;
		}
}

int gsize, head[maxn], sp[maxn];
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

int dijkstra(int ps, int pe) {
    priority_queue<node, vector<node>, greater<node> > q;
    memset(sp, inf, sizeof sp); sp[ps] = 0;
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
	return sp[pe];
}

void init() {
	memset(head, -1, sizeof head);
	memset(id, -1, sizeof id);
	sieve(1000);
	for (int i = 0; i < pnum - 1; i++)
		for (int j = i + 1; j < pnum; j++) {
			int x = prime[i], y = prime[j], diff = 0;
			for (int k = 0; k < 3; k++) {
				if (x % 10 != y % 10) diff++;
				x /= 10; y /= 10;
			}
			if (diff == 1) {
				add_edge(i, j, 1);
				add_edge(j, i, 1);
			}
		}
}

int main() {
	init();
	int x, y;
	while (scanf("%d %d", &x, &y) == 2 && x && y) {
		if (id[x] == -1 || id[y] == -1) { puts("Impossible"); continue; }
		int ans = dijkstra(id[x], id[y]);
		if (ans != inf)
			printf("%d\n", dijkstra(id[x], id[y]));
		else
			puts("Impossible");
	}
	return 0;
}
