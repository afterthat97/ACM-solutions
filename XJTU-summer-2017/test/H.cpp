#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#define inf 0x3f3f3f3f
#define fst first
#define snd second
using namespace std;

struct node {
	int l, r;
	node(): l(-inf), r(inf) {}
};

int n, m, _n;
node* tree;
typedef pair<int, int> seg;

void init() {
	_n = 1;
	while (_n < n) _n <<= 1;
	tree = new node[_n << 1];
	for (int i = _n; i < _n + n; i++)
		scanf("%d %d", &tree[i].l, &tree[i].r);
	for (int p = _n >> 1; p; p >>= 1)
		for (int i = p; i < (p << 1); i++) {
			int lt = i << 1, rt = (i << 1) + 1;
			tree[i].l = max(tree[lt].l, tree[rt].l);
			tree[i].r = min(tree[lt].r, tree[rt].r);
		}
}

seg query(int k, int l, int r, int a, int b) {
	if (r < a || l > b) return seg(-inf, inf);
	if (a <= l && r <= b) return seg(tree[k].l, tree[k].r);
	int mid = (r + l) >> 1, lt = k << 1, rt = (k << 1) + 1;
	seg s1 = query(lt, l, mid, a, b);
	seg s2 = query(rt, mid + 1, r, a, b);
	return seg(max(s1.fst, s2.fst), min(s1.snd, s2.snd));
}

int main() {
	while (scanf("%d %d", &n, &m) == 2) {
		init(); int x, y;
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &x, &y);
			seg ans = query(1, 1, _n, x, y);
			printf("%d\n", (ans.snd - ans.fst) < 0 ? 0 : ans.snd - ans.fst);
		}
		delete[] tree;
	}
	return 0;
}
