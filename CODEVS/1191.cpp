#include <iostream>
#include <stdio.h>
#define INF 0x3f3f3f3f
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)
using namespace std;

const int maxn = 1 << 22;

struct node {
	int setv, sumv, minv, maxv;
}tree[maxn];

int a, b, v, n, m;

inline void maintain(int k, int l, int r) {
	int lt = k << 1, rt = (k << 1) + 1;
	if (tree[k].setv > -INF) {
		tree[k].maxv = tree[k].minv = tree[k].setv;
		tree[k].sumv = tree[k].setv*(r - l + 1);
	} else {
		tree[k].sumv = tree[lt].sumv + tree[rt].sumv;
		tree[k].maxv = max(tree[lt].maxv, tree[rt].maxv);
		tree[k].minv = min(tree[lt].minv, tree[rt].minv);
	}
}

inline void update(int k, int l, int r) {
	int lt = k << 1, rt = (k << 1) + 1;
	if (a <= l && r <= b)
		tree[k].setv = v;
	else {
		if (tree[k].setv > -INF) {//push_down operation
			tree[lt].setv = tree[rt].setv = tree[k].setv;
			tree[k].setv = -INF;
		}
		int mid = (l + r) >> 1;
		if (a <= mid)
			update(lt, l, mid);
		else
			maintain(lt, l, mid);
		if (mid < b)
			update(rt, mid + 1, r);
		else
			maintain(rt, mid + 1, r);
	}
	maintain(k, l, r);
}

inline void query(int k, int l, int r, node& ans) {
	if (tree[k].setv > -INF) {
		ans.sumv += tree[k].setv*(min(r, b) - max(l, a) + 1);
		ans.minv = min(ans.minv, tree[k].minv);
		ans.maxv = max(ans.maxv, tree[k].maxv);
	} else if (a <= l && r <= b) {
		ans.sumv += tree[k].sumv;
		ans.minv = min(ans.minv, tree[k].minv);
		ans.maxv = max(ans.maxv, tree[k].maxv);
	} else {
		int mid = (r + l) >> 1;
		if (a <= mid) query((k << 1), l, mid, ans);
		if (mid < b) query((k << 1) + 1, mid + 1, r, ans);
	}
}

void init() {
	int _n = 1;
	while (_n < n) _n <<= 1;
	for (int i = _n; i < _n + n; i++) {
		tree[i].setv = 1;
		tree[i].maxv = tree[i].minv = tree[i].sumv = tree[i].setv;
	}
	for (int i = _n + n; i < _n * 2; i++) {
		tree[i].sumv = tree[i].setv = 0;
		tree[i].maxv = -INF;
		tree[i].minv = INF;
	}
	n = _n;
	while (_n > 1) {
		_n >>= 1;
		for (int i = _n; i < 2 * _n; i++) {
			tree[i].sumv = tree[i << 1].sumv + tree[(i << 1) + 1].sumv;
			tree[i].minv = min(tree[i << 1].minv, tree[(i << 1) + 1].minv);
			tree[i].maxv = max(tree[i << 1].maxv, tree[(i << 1) + 1].maxv);
			tree[i].setv = -INF;
		}
	}
}

inline void set(int l, int r, int x) {//for use
	a = l; b = r; v = x;
	update(1, 1, n);
}

inline node ask(int l, int r) {//for use
	a = l; b = r;
	node ans = { 0,0,INF,-INF };
	query(1, 1, n, ans);
	return ans;
}

int main() {
	scanf("%d", &n);
	init();
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		set(a, b, 0);
		node ans = ask(1, n);
		printf("%d\n", ans.sumv);
	}
	return 0;
}