#include <iostream>
#include <stdio.h>
#include <cstring>
#include <map>
#define maxn 10005
using namespace std;

struct edge {
	int to, next;
}g[maxn * 5];

typedef pair<int, int> pr;
int head[maxn], gsize, ps, pe, pass, trans, ans[maxn], way[maxn], vis[maxn];
map<pr, int> bel;

inline void add_edge(int from, int to) {
	g[gsize].to = to;
	g[gsize].next = head[from];
	head[from] = gsize++;
}

inline int cul(int k) {
	int pre = bel[pr(way[0], way[1])], ans = 0;
	for (int i = 2; i <= k; i++)
		if (bel[pr(way[i - 1], way[i])] != pre) {
			ans++;
			pre = bel[pr(way[i - 1], way[i])];
		}
	return ans;
}

void dfs(int x, int k) {
	way[k] = x;
	if (x == pe && k < pass) {
		for (int i = 0; i <= k; i++) ans[i] = way[i];
		pass = k;
		trans = cul(k);
	} else if (x == pe && k == pass && cul(k) < trans) {
		trans = cul(k);
		for (int i = 0; i <= k; i++) ans[i] = way[i];
	}
	if (x == pe || k > pass) return;
	for (int i = head[x]; ~i; i = g[i].next)
		if (!vis[g[i].to]) {
			vis[g[i].to] = 1;
			dfs(g[i].to, k + 1);
			vis[g[i].to] = 0;
		}
}

int main() {
	memset(head, -1, sizeof head);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int k, pre, cnt; cin >> k >> pre;
		for (int j = 1; j < k; j++) {
			scanf("%d", &cnt);
			add_edge(pre, cnt); add_edge(cnt, pre);
			bel[pr(cnt, pre)] = bel[pr(pre, cnt)] = i;
			pre = cnt;
		}
	}
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> ps >> pe;
		pass = trans = 0x3f3f3f3f;
		memset(vis, 0, sizeof vis); vis[ps] = 1;
		dfs(ps, 0);
		if (pass == 0x3f3f3f3f) {
			puts("Sorry, no line is available.");
			continue;
		} else {
			printf("%d\n", pass);
			int pre = bel[pr(ans[0], ans[1])], b = ps;
			for (int i = 2; i <= pass; i++)
				if (bel[pr(ans[i], ans[i - 1])] != pre) {
					printf("Go by the line of company #%d from %04d to %04d.\n", pre, b, ans[i - 1]);
					b = ans[i - 1];
					pre = bel[pr(ans[i], ans[i - 1])];
				}
			printf("Go by the line of company #%d from %04d to %04d.\n", pre, b, ans[pass]);
		}
	}
	return 0;
}
