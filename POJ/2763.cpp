#include <iostream>
#include <stdio.h>
#include <cstring>
#define maxn 200005
#define maxm 200005
#define fst first
#define snd second
#define MAX_LGN 18
#define ll long long
using namespace std;

pair<int, int> st[MAX_LGN][1 << MAX_LGN];
int tree[maxn];

inline void init_st(int* a, int n) { // a[0 ~ n-1]
	for (int j = 0; j < n; j++) st[0][j] = { a[j], j };
	for (int i = 1; (1 << i) <= n; i++)
		for (int j = 0; j <= n - (1 << i); j++)
			st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
}

inline int query(int l, int r) { // l, r: [0, n-1]
	int i = 0;
	while ((1 << (i + 1)) <= r - l + 1) i++;
	return min(st[i][l], st[i][r - (1 << i) + 1]).snd;
}

struct edge {
	int to, next, cost;
} g[maxm << 1];

int head[maxn], gsize, np, ne, ps, m;

inline ll sum(int x) {
	x++;
	ll ans = 0;
	for (; x > 0; x -= (x & -x))
		ans += tree[x];
	return ans;
}

inline void add(int x, int val) {
	x++;
	for (; x <= np * 2; x += (x & -x))
		tree[x] += val;
}

inline void add_edge(int from, int to, int cost) {
	g[gsize] = { to, head[from], cost };
	head[from] = gsize++;
}

int vs[maxn], depth[maxn], pid[maxn], eid[maxn];

void dfs(int v, int pre, int dep, int& k) {
	pid[v] = k; vs[k] = v; depth[k++] = dep;
	for (int i = head[v]; ~i; i = g[i].next)
		if (g[i].to != pre) {
			add(k, g[i].cost);
			eid[(i / 2) * 2] = k;
			dfs(g[i].to, v, dep + 1, k);
			add(k, -g[i].cost);
			eid[(i / 2) * 2 + 1] = k;
			vs[k] = v; depth[k++] = dep;
		}
}

void init_lca(int root) {
	int k = 0;
	dfs(root, -1, 0, k);
}

inline int lca(int u, int v) {
	return vs[query(min(pid[u], pid[v]), max(pid[u], pid[v]))];
}

int main() {
	while (scanf("%d %d %d", &np, &m, &ps) == 3 && np) {
		ne = np - 1; ps--; gsize = 0;
		memset(head, -1, sizeof head);
		memset(tree, 0, sizeof tree);
		for (int i = 1; i < np; i++) {
			int px, py, w;
			scanf("%d %d %d", &px, &py, &w);
			add_edge(px - 1, py - 1, w);
			add_edge(py - 1, px - 1, w);
		}
		init_lca(0);
		init_st(depth, np * 2 - 1);
		for (int i = 0; i < m; i++) {
			int cho; scanf("%d", &cho);
			if (cho == 0) {
				int pe; scanf("%d", &pe); pe--;
				int p = lca(ps, pe);
				printf("%lld\n", sum(pid[ps]) + sum(pid[pe]) - 2 * sum(pid[p]));
				ps = pe;
			} else {
				int id, w; scanf("%d %d", &id, &w); id--;
				add(eid[id * 2], w - g[id * 2].cost);
				add(eid[id * 2 + 1], g[id * 2].cost - w);
				g[id * 2].cost = g[id * 2 + 1].cost = w;
			}
		}
	}
	return 0;
}
