#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>
#define MAXN 1000005
using namespace std;

int len;

struct node {
	int l, r, id, block;
	node() {}
	node(int ll, int rr, int dd) {
		l = ll; r = rr; id = dd;
		block = l / len;
	}
}query[MAXN];

bool cmp(const node& a, const node& b) {
	if (a.block != b.block) return a.block < b.block;
	return a.r < b.r;
}

int tree[MAXN], c[MAXN], pre[MAXN], prec[MAXN], ans[MAXN], n, m;

inline int sum(int x) {
	int ans = 0;
	for (; x > 0; x -= (x & -x))
		ans += tree[x];
	return ans;
}

inline void add(int x, int val) {
	if (x == 0) return;
	for (; x <= n; x += (x & -x))
		tree[x] += val;
}

int main() {
	scanf("%d %*d %d", &n, &m);
	len = sqrt(n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	for (int i = 1; i <= n; i++) {
		pre[i] = prec[c[i]];
		prec[c[i]] = i;
	}
	for (int i = 0; i < m; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		query[i] = node(l, r, i);
	}
	sort(query, query + m, cmp);
	int l = 1, r = 1;
	for (int i = 0; i < m; i++) {
		while (r < query[i].r) { r++; add(pre[r], 1); add(pre[pre[r]], -1); }
		//while (l > query[i].l) { l--; add(pre[l], 1); add(pre[pre[l]], -1); }
		while (r > query[i].r) { add(pre[r], -1); add(pre[pre[r]], 1); r--; }
		//while (l < query[i].l) { add(pre[l], -1); add(pre[pre[l]], 1); l++; }
		ans[query[i].id] = sum(query[i].r) - sum(query[i].l - 1);
	}
	for (int i = 0; i < m; i++) printf("%d\n", ans[i]);
	return 0;
}
