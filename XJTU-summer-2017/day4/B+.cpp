#include <iostream>
#include <stdio.h>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;

struct node {
	int addv, maxv, minv;
	node(): maxv(-INF), minv(INF), addv(0) {}
};

int n, m, _n, a[100005];
node* tree;

void init() {
	_n = 1;
	while (_n < n) _n <<= 1;
	tree = new node[_n << 1];
	for (int i = _n; i < _n + n; i++) { 
		scanf("%d", &tree[i].addv);
		a[i - _n + 1] = tree[i].maxv = tree[i].minv = tree[i].addv;
	}
	for (int p = _n >> 1; p; p >>= 1)
		for (int i = p; i < (p << 1); i++) {
			int lt = i << 1, rt = (i << 1) + 1;
			tree[i].maxv = max(tree[lt].maxv, tree[rt].maxv);
			tree[i].minv = min(tree[lt].minv, tree[rt].minv);
		}
}

inline void maintain(int k, int l, int r) {
	int lt = k << 1, rt = (k << 1) + 1;
	tree[k].maxv = tree[k].minv = 0;
	if (r > l) {
		tree[k].maxv = max(tree[lt].maxv, tree[rt].maxv);
		tree[k].minv = min(tree[lt].minv, tree[rt].minv);
	}
	tree[k].maxv += tree[k].addv;
	tree[k].minv += tree[k].addv;
}

inline void push_down(int k) {
	int lt = k << 1, rt = (k << 1) + 1;
	tree[lt].addv += tree[k].addv;
	tree[rt].addv += tree[k].addv;
	tree[k].addv = 0;
}

inline void flag(int k, int v) { tree[k].addv += v; }

inline void update(int k, int l, int r, int a, int b, int v) {
	int lt = k << 1, rt = (k << 1) + 1;
	if (a <= l && r <= b)
		flag(k, v);
	else {
		push_down(k);
		int mid = (l + r) >> 1;
		if (a <= mid) update(lt, l, mid, a, b, v); 
			else maintain(lt, l, mid);
		if (mid < b) update(rt, mid + 1, r, a, b, v); 
			else maintain(rt, mid + 1, r);
	}
	maintain(k, l, r);
}

int query_max(int k, int l, int r, int a, int b, int add) {
	if (r < a || l > b) return -INF;
	if (a <= l && r <= b) return tree[k].maxv + add;
	int mid = (r + l) >> 1, lt = k << 1, rt = (k << 1) + 1;
	return max(query_max(lt, l, mid, a, b, add + tree[k].addv),
			query_max(rt, mid + 1, r, a, b, add + tree[k].addv));
}

int query_min(int k, int l, int r, int a, int b, int add) {
	if (r < a || l > b) return INF;
	if (a <= l && r <= b) return tree[k].minv + add;
	int mid = (r + l) >> 1, lt = k << 1, rt = (k << 1) + 1;
	return min(query_min(lt, l, mid, a, b, add + tree[k].addv),
			query_min(rt, mid + 1, r, a, b, add + tree[k].addv));
}

int main() {
	int cho, x, y;
	scanf("%d %d", &n, &m);
	init();
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &cho, &x, &y);
		if (cho == 1) {
			update(1, 1, _n, x, x, a[y] - a[x]);
			update(1, 1, _n, y, y, a[x] - a[y]);
			swap(a[x], a[y]);
		} else {
			int minn = query_min(1, 1, _n, x, y, 0);
			int maxx = query_max(1, 1, _n, x, y, 0);
			if (y - x == maxx - minn) puts("YES"); else puts("NO");
		}
	}
	return 0;
}
