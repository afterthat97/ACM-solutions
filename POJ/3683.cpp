#include <iostream>
#include <stdio.h>
#include <cstring>
#define maxn 2050
#define maxm (1010 * 1010 * 4)
using namespace std;

struct edge {
	int to, next;
} g[maxm], rg[maxm];

int vis[maxn], order[maxn], bel[maxn], cnt;
int n, np, ne, head[maxn], rhead[maxn], gsize, rgsize;
int st[maxn], ed[maxn], dur[maxn];

inline void add_edge(int from, int to) {
	g[gsize] = { to, head[from] };
	rg[rgsize] = { from, rhead[to] };
	head[from] = gsize++;
	rhead[to] = rgsize++;
}

void dfs(int v) {
	vis[v] = 1;
	for (int i = head[v]; ~i; i = g[i].next)
		if (!vis[g[i].to]) dfs(g[i].to);
	order[cnt++] = v;
}

void rdfs(int v, int k) {
	vis[v] = 1; bel[v] = k;
	for (int i = rhead[v]; ~i; i = rg[i].next)
		if (!vis[rg[i].to]) rdfs(rg[i].to, k);
}

int scc() {
	memset(vis, 0, sizeof vis); cnt = 0;
	for (int i = 0; i < np; i++)
		if (!vis[i]) dfs(i);
	memset(vis, 0, sizeof vis);
	int k = 0;
	for (int i = cnt - 1; ~i; i--)
		if (!vis[order[i]]) rdfs(order[i], k++);
	return k;
}

int main() {
	while (scanf("%d", &n) == 1) {
		memset(head, -1, sizeof head);
		memset(rhead, -1, sizeof rhead);
		gsize = rgsize = 0;
		for (int i = 0; i < n; i++) {
			int h1, m1, h2, m2, t;
			scanf("%d:%d %d:%d %d", &h1, &m1, &h2, &m2, &t);
			st[i] = h1 * 60 + m1;
			ed[i] = h2 * 60 + m2;
			dur[i] = t;
		}
		np = n * 2;
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++) {
				if (min(st[i] + dur[i], st[j] + dur[j]) > max(st[i], st[j])) {
					// !xi or !xj: xi -> !xj and xj -> !xi
					add_edge(i, j + n);
					add_edge(j, i + n);
				}
				if (min(st[i] + dur[i], ed[j]) > max(st[i], ed[j] - dur[j])) {
					// !xi or xj: xi -> xj and !xj -> !xi
					add_edge(i, j);
					add_edge(j + n, i + n);
				}
				if (min(st[j] + dur[j], ed[i]) > max(st[j], ed[i] - dur[i])) {
					// xi or !xj: !xi -> !xj and xj -> xi
					add_edge(i + n, j + n);
					add_edge(j, i);
				}
				if (min(ed[i], ed[j]) > max(ed[i] - dur[i], ed[j] - dur[j])) {
					// xi or xj: !xi -> xj and !xj -> xi
					add_edge(i + n, j);
					add_edge(j + n, i);
				}
			}
		scc();
		bool succ = 1;
		for (int i = 0; i < n; i++)
			if (bel[i] == bel[i + n]) {
				puts("NO"); succ = 0;
				break;
			}
		if (!succ) continue;
		puts("YES");
		for (int i = 0; i < n; i++)
			if (bel[i] > bel[i + n])
				printf("%02d:%02d %02d:%02d\n", st[i] / 60, st[i] % 60, (st[i] + dur[i]) / 60, (st[i] + dur[i]) % 60);
			else
				printf("%02d:%02d %02d:%02d\n", (ed[i] - dur[i]) / 60, (ed[i] - dur[i]) % 60, ed[i] / 60, ed[i] % 60);


	}
	return 0;
}
