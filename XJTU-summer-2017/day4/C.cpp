#include <iostream>
#include <stdio.h>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;

struct node {
	int num[11];
	node() { memset(num, 0, sizeof num); }
};

int n, m, _n, a[100005];
node* tree;

void init() {
	_n = 1;
	while (_n < n) _n <<= 1;
	tree = new node[_n << 1];
	for (int i = _n; i < _n + n; i++) { 
		scanf("%d", &a[i - _n + 1]); 
		tree[i].num[a[i - _n + 1]] = 1;
	}
	for (int p = _n >> 1; p; p >>= 1)
		for (int i = p; i < (p << 1); i++) {
			int lt = i << 1, rt = (i << 1) + 1;
			for (int k = 1; k <= 10; k++)
				tree[i].num[k] = tree[lt].num[k] + tree[rt].num[k];
		}
}

inline void update(int k, int v) {
	int kk = k + _n - 1, tmp = a[k];
	while (kk > 0) {
		tree[kk].num[a[k]]--;
		tree[kk].num[v]++;
		kk >>= 1;
	}
	a[k] = v;	
}

int query(int k, int l, int r, int a, int b, int val) {
	if (r < a || l > b) return 0;
	if (a <= l && r <= b) return tree[k].num[val];
	int mid = (r + l) >> 1, lt = k << 1, rt = (k << 1) + 1;
	return query(lt, l, mid, a, b, val) + query(rt, mid + 1, r, a, b, val);
}

int main() {
	int cho, x, y, z;
	scanf("%d %d", &n, &m);
	init();
	for (int i = 0; i < m; i++) {
		scanf("%d", &cho);
		if (cho == 1) {
			scanf("%d %d", &x, &y);
			update(x, y);
		} else {
			scanf("%d %d %d", &x, &y, &z);
			printf("%d\n", query(1, 1, _n, x, y, z));
		}
	}
	return 0;
}
