#include <iostream>
#include <stdio.h>
#include <queue>
#include <cstring>
#include <cmath>
#include <algorithm>
#define maxn 550
#define maxm 250050
#define inf 0x3f3f3f3f
#define fst first
#define snd second
using namespace std;

struct edge {
	int to, next, val;
}g[maxm * 2];

struct node {
	int val, from, to;
	node(int _val, int _from, int _to) {
		val = _val; from = _from; to = _to;
	}
};

bool operator < (const node& a, const node& b) {
	return a.val < b.val;
}

bool operator > (const node& a, const node& b) {
	return a.val > b.val;
}

typedef pair<int, int> point;
point p[maxn];
int cnt, s, np, ne, gsize, head[maxn], minc[maxn], flag[maxn], tree[maxn];
bool vis[maxn];

inline void add_edge(int from, int to, int val) {
	g[gsize] = { to, head[from], val };
	head[from] = gsize++;
}

inline int dis(const point& a, const point& b) {
	int dx = a.fst - b.fst, dy = a.snd - b.snd;
	return dx * dx + dy * dy;
}

void prim() {
	priority_queue<node, vector<node>, greater<node> > q;
	q.push(node(0, -1, 1)); minc[1] = 0;
	while (!q.empty()) {
		node now = q.top(); q.pop();
		if (vis[now.to] || now.val > minc[now.to]) continue;
		vis[now.to] = 1;
		tree[cnt++] = now.val;
		for (int i = head[now.to]; ~i; i = g[i].next)
			if (minc[g[i].to] > g[i].val) {
				minc[g[i].to] = g[i].val;
				q.push(node(g[i].val, now.to, g[i].to));
			}
	}
}

int main() {
	int T; cin >> T;
	while (T--) {
		cnt = gsize = 0;
		memset(head, -1, sizeof head);
		memset(flag, 0, sizeof flag);
		memset(minc, inf, sizeof minc);
		memset(vis, 0, sizeof vis);
		scanf("%d %d", &s, &np);
		ne = (np - 1) * np / 2;
		for (int i = 0; i < np; i++)
			scanf("%d %d", &p[i].fst, &p[i].snd);
		for (int i = 0; i < np - 1; i++)
			for (int j = i + 1; j < np; j++) {
				int d = dis(p[i], p[j]);
				add_edge(i, j, d);
				add_edge(j, i, d);
			}
		prim();
		sort(tree, tree + cnt);
		printf("%.2f\n", sqrt(tree[cnt - s]));
	}
	return 0;
}
