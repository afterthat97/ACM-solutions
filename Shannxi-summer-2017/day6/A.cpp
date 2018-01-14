#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

struct node {
	int val, opt;//opt: 0 = or, 1 = xor;
	node(): val(0), opt(1) {}
};

int n, m, _n;
node* tree;

void init() {
	_n = 1;
	while (_n < n) _n <<= 1;
	tree = new node[_n << 1];
	for (int i = _n; i < _n + n; i++)
		scanf("%d", &tree[i].val);
	for (int p = _n >> 1; p; p >>= 1)
		for (int i = p; i < (p << 1); i++) {
			int lt = i << 1, rt = (i << 1) + 1;
			tree[i].opt = 1 - tree[lt].opt;
			if (tree[i].opt)
				tree[i].val = tree[lt].val ^ tree[rt].val;
			else
				tree[i].val = tree[lt].val | tree[rt].val;
		}
}

int update(int k, int v) {
	k += _n - 1; tree[k].val = v;
	while (k > 1) {
		k >>= 1;
		int lt = k << 1, rt = (k << 1) + 1;
		if (tree[k].opt)
			tree[k].val = tree[lt].val ^ tree[rt].val;
		else
			tree[k].val = tree[lt].val | tree[rt].val;
	}
	return tree[1].val;
}

int pow(int n, int k) {
	int ans = 1;
	for (int i = 0; i < k; i++)
		ans *= n;
	return ans;
}

int main() {
	scanf("%d %d", &n, &m);
	n = pow(2, n);
	init();
	for (int i = 0; i < m; i++) {
		int pos, v;
		scanf("%d %d", &pos, &v);
		printf("%d\n", update(pos, v));
	}
	return 0;
}
