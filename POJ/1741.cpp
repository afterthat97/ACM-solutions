#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#define fst first
#define snd second
#define inf 0x7fffffff
#define maxn 10005
#define maxm 10005
using namespace std;

struct edge {
	int to, next, val;
}g[maxm << 1];

int center[maxn], sub_size[maxn], dis[maxn], head[maxn], gsize, n, k;

inline void add_edge(int from, int to, int val) {
	g[gsize] = {to, head[from], val};
	head[from] = gsize++;
}

int subtree_size(int v, int pre) {// init pre = -1
	int cnt = 1;
	for (int i = head[v]; ~i; i = g[i].next) {
		if (g[i].to == pre || center[g[i].to]) continue;
		cnt += subtree_size(g[i].to, v);
	}
	return sub_size[v] = cnt;
}

pair<int, int> get_center(int v, int pre, int tot) {
	pair<int, int> ans = make_pair(inf, -1);
	int m = 0, cnt = 0;
	for (int i = head[v]; ~i; i = g[i].next) {
		if (g[i].to == pre || center[g[i].to]) continue;
		ans = min(ans, get_center(g[i].to, v, tot));
		m = max(m, sub_size[g[i].to]);
		cnt += sub_size[g[i].to];
	}
	m = max(m, tot - cnt);
	ans = min(ans, make_pair(m, v));
	return ans;
}

void path_length(int v, int pre, int d, int* dis, int& cnt) {
	dis[cnt++] = d;
	for (int i = head[v]; ~i; i = g[i].next) {
		if (g[i].to == pre || center[g[i].to]) continue;
		path_length(g[i].to, v, d + g[i].val, dis, cnt);
	}
}

int count_pair(int* dis, int& cnt) {
	sort(dis, dis + cnt);
	int tot = 0;
	for (int st = 0, ed = cnt; st < cnt; st++) {
		while (ed > 0 && dis[st] + dis[ed - 1] > k) ed--;
		tot += max(ed - st - 1, 0);
	}
	return tot;
}

int solve(int v) {
	if (center[v]) return 0;
	int s = get_center(v, -1, subtree_size(v, -1)).snd;
	center[s] = 1;
	int cnt = 0, ans = 0; dis[cnt++] = 0;
	for (int i = head[s]; ~i; i = g[i].next) {
		if (center[g[i].to]) continue;
		int tmpcnt = 0;
		path_length(g[i].to, s, g[i].val, dis + cnt, tmpcnt);
		ans -= count_pair(dis + cnt, tmpcnt);
		cnt += tmpcnt;
	}
	ans += count_pair(dis, cnt);
	for (int i = head[s]; ~i; i = g[i].next)
		ans += solve(g[i].to);
	center[s] = 0;
	return ans;
}

int main() {
	while (scanf("%d %d", &n, &k) == 2 && n && k) {
		memset(head, -1, sizeof head); gsize = 0;
		for (int i = 1; i < n; i++) {
			int px, py, w;
			scanf("%d %d %d", &px, &py, &w);
			add_edge(px, py, w);
			add_edge(py, px, w);
		}
		printf("%d\n", solve(1));
	}
	return 0;
}
