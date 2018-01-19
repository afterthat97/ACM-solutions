#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#define maxn 500
#define maxm 30000
#define inf 0x3f3f3f3f
using namespace std;

struct node {
    int to, next, cap;
}g[maxm << 1];

int gsize, head[maxn], n;
bool used[maxn];

inline void add_edge(int from, int to, int cap) {
    g[gsize] = {to, head[from], cap};
    head[from] = gsize++;
	g[gsize] = {from, head[to], 0};
	head[to] = gsize++;
}

int dfs(int v, int pe, int flow) {
	if (v == pe) return flow;
	used[v] = 1;
	for (int i = head[v]; ~i; i = g[i].next)
		if (!used[g[i].to] && g[i].cap > 0) {
			int d = dfs(g[i].to, pe, min(flow, g[i].cap));
			if (d > 0) {
				g[i].cap -= d; g[i^1].cap += d;
				return d;
			}
		}
	return 0;
}

int max_flow(int ps, int pe) {
	int ans = 0, f = 0;
	memset(used, 0, sizeof used);
	while (f = dfs(ps, pe, inf)) {
		memset(used, 0, sizeof used);
		ans += f;
	}
	return ans;
}

const int ST = 0, F = 0, N1 = 100, N2 = 200, D = 300, ED = 401;

int main() {
	while (scanf("%d %*d %*d", &n) == 1) {
		memset(head, -1, sizeof head); gsize = 0;
		for (int i = 1; i <= n; i++) {
			int fi, di;
			scanf("%d %d", &fi, &di);
			for (int j = 0; j < fi; j++) {
				int t; scanf("%d", &t);
				add_edge(F + t, N1 + i, 1);
			}
			for (int j = 0; j < di; j++) {
				int t; scanf("%d", &t);
				add_edge(N2 + i, D + t, 1);
			}
			add_edge(N1 + i, N2 + i, 1);
		}
		for (int i = 1; i <= 100; i++) {
			add_edge(ST, F + i, 1);
			add_edge(D + i, ED, 1);
		}
		printf("%d\n", max_flow(ST, ED));
	}
	return 0;
}
