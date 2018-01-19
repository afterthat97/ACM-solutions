#include <iostream>
#include <stdio.h>
#include <algorithm>
#define MAXN 1000005
using namespace std;

struct node {
	int l, r, id;
	node(int ll = 0, int rr = 0, int dd = 0) {
		l = ll; r = rr; id = dd;
	}
}query[MAXN];

bool cmp(const node& a, const node& b) { return a.r < b.r; }

int tree[MAXN], c[MAXN], pre[MAXN], prec[MAXN], ans[MAXN], n, m;

inline int sum(int x) {//x: [1, n]
	int ans = 0;
	for (; x > 0; x -= (x & -x))
		ans += tree[x];
	return ans;
}

inline void add(int x, int val) {//x: [1, n]
	if (x == 0) return;
	for (; x <= n; x += (x & -x))
		tree[x] += val;
}

int main() {
	scanf("%d %*d %d", &n, &m);
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
	for (int i = 1, cnt = 0; i <= n; i++) {
		add(pre[i], 1);
		add(pre[pre[i]], -1);
		while (query[cnt].r == i) {
			ans[query[cnt].id] = sum(i) - sum(query[cnt].l - 1);
			cnt++;
		}
	}
	for (int i = 0; i < m; i++) printf("%d\n", ans[i]);
	return 0;
}
