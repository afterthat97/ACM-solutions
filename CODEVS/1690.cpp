#include <stdio.h>
#define INF 0x7fffffff
#define uint unsigned int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
using namespace std;
const int maxn = 1 << 18;//262144

struct node {
	int sumv, minv, maxv, addv;
}tree[maxn], ans;

uint n, a, b, v, m;

inline void init() {
	uint _n = 1;
	while (_n < n) _n <<= 1;
	for (uint i = _n; i < _n + n; i++) {
		tree[i].addv = 0;
		tree[i].maxv = tree[i].minv = tree[i].sumv = tree[i].addv;
	}
	for (uint i = _n + n; i < _n * 2; i++) {
		tree[i].sumv = tree[i].addv = 0;
		tree[i].maxv = -INF;
		tree[i].minv = INF;
	}
	n = _n;
	while (_n > 1) {
		_n >>= 1;
		for (uint i = _n; i < 2 * _n; i++) {
			tree[i].sumv = tree[i << 1].sumv + tree[(i << 1) + 1].sumv;
			tree[i].minv = min(tree[i << 1].minv, tree[(i << 1) + 1].minv);
			tree[i].maxv = max(tree[i << 1].maxv, tree[(i << 1) + 1].maxv);
			tree[i].addv = 0;
		}
	}
}

inline void maintain(uint k, uint l, uint r) {
	uint lt = k << 1, rt = (k << 1) + 1;
	tree[k].maxv = tree[k].minv = tree[k].sumv = 0;
	if (r > l) {
		tree[k].sumv = tree[lt].sumv + tree[rt].sumv;
		tree[k].minv = min(tree[lt].minv, tree[rt].minv);
		tree[k].maxv = max(tree[lt].maxv, tree[rt].maxv);
	}
	tree[k].minv += tree[k].addv;
	tree[k].maxv += tree[k].addv;
	if (tree[k].addv > 0) {
		tree[k].sumv = (r - l + 1) - tree[k].sumv;
	}
}

inline void update(uint k, uint l, uint r) {
	if (a <= l && b >= r)
		tree[k].addv = (tree[k].addv + v) % 2;
	else {
		uint mid = (r + l) >> 1;
		if (a <= mid) update(k << 1, l, mid);
		if (mid < b) update((k << 1) + 1, mid + 1, r);
	}
	maintain(k, l, r);
}

inline void query(uint k, uint l, uint r, int add) {
	if (a <= l && r <= b) {
		if (add % 2)
			ans.sumv += (r - l + 1) - tree[k].sumv;
		else
			ans.sumv += tree[k].sumv;
		ans.minv = min(ans.minv, tree[k].minv + add);
		ans.maxv = max(ans.maxv, tree[k].maxv + add);
	} else {
		uint mid = (r + l) >> 1;
		if (a <= mid) query(k << 1, l, mid, add + tree[k].addv);
		if (mid < b) query((k << 1) + 1, mid + 1, r, add + tree[k].addv);
	}
}

int main() {
	scanf("%d", &n);
	init();
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int cho;
		scanf("%d", &cho);
		if (cho == 0) {//add
			scanf("%d %d", &a, &b);
			v = 1;
			update(1, 1, n);
		} else {
			scanf("%d %d", &a, &b);
			ans = { 0, INF, -INF, 0 };
			query(1, 1, n, 0);
			printf("%d\n", ans.sumv);
		}
	}
	return 0;
}