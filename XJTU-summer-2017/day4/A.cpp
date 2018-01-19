#include <iostream>
#include <stdio.h>
#include <cstring>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;

struct node {
	ll addv, sumv;
	node(): sumv(0), addv(0) {}
};

int n, m, _n;
node* tree;

void init() {
	_n = 1;
	while (_n < n) _n <<= 1;
	tree = new node[_n << 1];
	for (int i = _n; i < _n + n; i++) { 
		scanf("%lld", &tree[i].addv); 
		tree[i].sumv = tree[i].addv;
	}
	for (int p = _n >> 1; p; p >>= 1)
		for (int i = p; i < (p << 1); i++) {
			int lt = i << 1, rt = (i << 1) + 1;
			tree[i].sumv = tree[lt].sumv + tree[rt].sumv;
		}
}

inline void maintain(int k, int l, int r) {
	int lt = k << 1, rt = (k << 1) + 1;
	tree[k].sumv = 0;
	if (r > l) {
		tree[k].sumv = tree[lt].sumv + tree[rt].sumv;
	}
	tree[k].sumv += tree[k].addv * (r - l + 1);
}

inline void push_down(int k) {
	int lt = k << 1, rt = (k << 1) + 1;
	tree[lt].addv += tree[k].addv;
	tree[rt].addv += tree[k].addv;
	tree[k].addv = 0;
}

inline void flag(int k, ll v) { tree[k].addv += v; }

inline void update(int k, int l, int r, int a, int b, ll v) {
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

ll query(int k, int l, int r, int a, int b, ll add) {
	if (r < a || l > b) return 0;//or INF, -INF
	if (a <= l && r <= b) return tree[k].sumv + add * (r - l + 1);
	int mid = (r + l) >> 1, lt = k << 1, rt = (k << 1) + 1;
	return query(lt, l, mid, a, b, add + tree[k].addv) 
		+ query(rt, mid + 1, r, a, b, add + tree[k].addv);
}

int main() {
	int cho, x, y; ll z;
	scanf("%d %d", &n, &m);
	init();
	for (int i = 0; i < m; i++) {
		scanf("%d", &cho);
		if (cho == 1) {
			scanf("%d %d %lld", &x, &y, &z);
			update(1, 1, _n, x, y, z);
		} else {
			scanf("%d", &x);
			printf("%lld\n", query(1, 1, _n, x, x, 0));
		}
	}
	return 0;
}
