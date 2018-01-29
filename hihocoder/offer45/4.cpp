#include <iostream>
#include <stdio.h>
#include <cstring>
#define maxn 100005
#define maxm 1000005
#define inf 0x3f3f3f3f
using namespace std;

struct edge {
	int to, next, val;
	edge(int t = 0, int n = 0, int v = 0):
		to(t), next(n), val(v) {}
}g[maxm * 2];

int np, ne, gsize, head[maxn], used[maxn], ans = inf;

inline void add_edge(int from, int to, int val) {
	if (from == to) return;
	g[gsize] = edge(to, head[from], val);
	head[from] = gsize++;
}

void dfs(int pre, int p, int maxv, int tar) {
	if (p == tar) {
		ans = min(ans, maxv);
		return;
	}
	if (maxv >= used[p]) return;
	used[p] = maxv;
	for (int i = head[p]; ~i; i = g[i].next)
		if (g[i].to != pre)
			dfs(p, g[i].to, max(maxv, g[i].val), tar);
}

int main() {
	memset(head, -1, sizeof head);
	scanf("%d %d", &np, &ne);
	for (int i = 1; i <= ne; i++) {
		int px, py; char opt;
		scanf(" A%d %c A%d", &px, &opt, &py);
		add_edge(px, py, i);
		if (opt == '=') add_edge(py, px, i);
	}
	memset(used, inf, sizeof used);
	dfs(0, 1, 0, np);
	memset(used, inf, sizeof used);
	dfs(0, np, 0, 1);
	cout << (ans == inf ? -1 : ans) << endl;
	return 0;
}
