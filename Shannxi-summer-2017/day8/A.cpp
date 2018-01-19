#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

struct node {
	int sumv;
	node(): sumv(0) {}
};

int n, m, _n;
node* tree;

void init() {
	_n = 1;
	while (_n < n) _n <<= 1;
	tree = new node[_n << 1];
	for (int i = _n; i < _n + n; i++)
		scanf("%d", &tree[i].sumv);
	for (int p = _n >> 1; p; p >>= 1)
		for (int i = p; i < (p << 1); i++) {
			int lt = i << 1, rt = (i << 1) + 1;
			tree[i].sumv = tree[lt].sumv + tree[rt].sumv;
		}
}

void update(int k, int v) {
	k += _n - 1;
	tree[k].sumv += v;
	while (k > 1) {
		k >>= 1;
		int lt = k << 1, rt = (k << 1) + 1;
		tree[k].sumv = tree[lt].sumv + tree[rt].sumv;
	}
}

inline int query(int k, int l, int r, int a, int b) {
	if (r < a || l > b) return 0;
	if (a <= l && r <= b) return tree[k].sumv;
	int mid = (r + l) >> 1, lt = k << 1, rt = (k << 1) + 1;
	return query(lt, l, mid, a, b) + query(rt, mid + 1, r, a, b);
}

char cmd[10];
int l, r, T;

int main() {
	cin >> T;
	for (int idx = 1; idx <= T; idx++) {
		scanf("%d", &n);
		init();
		printf("Case %d:\n", idx);
		while (1) {
			scanf("%s", cmd);
			if (cmd[0] == 'E') break;
			scanf("%d %d", &l, &r);
			if (cmd[0] == 'A') update(l, r);
			if (cmd[0] == 'S') update(l, -r);
			if (cmd[0] == 'Q')
				printf("%d\n", query(1, 1, _n, l, r));		
		}
		delete[] tree;
	}

	return 0;
}
