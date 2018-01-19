#include <stdio.h>
#define INF 0x7fffffffffffffff
#define ll long long
#define uint unsigned int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
using namespace std;
const uint maxn = 1 << 18;//262144

struct node {
	ll setv, sumv, minv, maxv, addv;
	node(ll setv = -INF, ll sumv = 0, ll minv = INF, ll maxv = -INF, ll addv = 0):
		setv(setv), sumv(sumv), minv(minv), maxv(maxv), addv(addv) {};
}tree[maxn];

uint n, a, b, m;
enum { ADD, SET, QUERY } OPT;

inline void init() {
	uint _n = 1;
	while (_n < n) _n <<= 1;
	for (uint i = _n; i < _n + n; i++) {
		scanf("%lld", &tree[i].addv);
		tree[i].maxv = tree[i].minv = tree[i].sumv = tree[i].addv;
	}
	n = _n;
	while (_n > 1) {
		_n >>= 1;
		for (uint i = _n; i < 2 * _n; i++) {
			uint lt = i << 1, rt = (i << 1) + 1;
			tree[i].sumv = tree[i << 1].sumv + tree[(i << 1) + 1].sumv;
			tree[i].minv = min(tree[i << 1].minv, tree[(i << 1) + 1].minv);
			tree[i].maxv = max(tree[i << 1].maxv, tree[(i << 1) + 1].maxv);
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
	if (tree[k].setv > -INF) {
		tree[k].setv += tree[k].addv;
		tree[k].addv = 0;
		tree[k].maxv = tree[k].minv = tree[k].setv;
		tree[k].sumv = tree[k].setv * (r - l + 1);
	} else {
		tree[k].minv += tree[k].addv;
		tree[k].maxv += tree[k].addv;
		tree[k].sumv += tree[k].addv * (r - l + 1);
	}
}

inline void update(uint k, uint l, uint r, ll &v) {
	uint lt = k << 1, rt = (k << 1) + 1;
	if (a <= l && b >= r) {
		if (OPT == ADD)
			tree[k].addv += v;
		else {
			tree[k].setv = v;
			tree[k].addv = 0;
		}
	} else {
		if (tree[k].setv > -INF) {//push_down operation
			tree[lt].setv = tree[rt].setv = tree[k].setv;
			tree[k].setv = -INF;
			tree[lt].addv = tree[rt].addv = 0;
		} else {
			tree[lt].addv += tree[k].addv;
			tree[rt].addv += tree[k].addv;
			tree[k].addv = 0;
		}
		int mid = (l + r) >> 1;
		maintain(lt, l, mid);
		maintain(rt, mid + 1, r);
		if (a <= mid) update(lt, l, mid, v);
		if (mid < b) update(rt, mid + 1, r, v);
	}
	maintain(k, l, r);
}

inline void query(uint k, uint l, uint r, ll add, node &ans) {
	if (tree[k].setv > -INF) {
		ans.sumv += (tree[k].setv + add) * (min(r, b) - max(l, a) + 1);
		ans.minv = min(ans.minv, tree[k].minv + add);
		ans.maxv = max(ans.maxv, tree[k].maxv + add);
	} else if (a <= l && r <= b) {
		ans.sumv += tree[k].sumv + add*(r - l + 1);
		ans.minv = min(ans.minv, tree[k].minv + add);
		ans.maxv = max(ans.maxv, tree[k].maxv + add);
	} else {
		uint mid = (r + l) >> 1;
		if (a <= mid) query(k << 1, l, mid, add + tree[k].addv, ans);
		if (mid < b) query((k << 1) + 1, mid + 1, r, add + tree[k].addv, ans);
	}
}

inline void add(uint x, uint y, ll val) {
	a = x; b = y;
	OPT = ADD;
	update(1, 1, n, val);
}

inline void set(uint x, uint y, ll val) {
	a = x; b = y;
	OPT = SET;
	update(1, 1, n, val);
}

inline node ask(uint x, uint y) {
	node ans;
	query(1, 1, n, 0, ans);
	return ans;
}

int main() {
	scanf("%d %d", &n, &m);
	ll v;
	init();
	for (int i = 0; i < m; i++) {
		char s[10];
		scanf("%s", s);
		if (s[1] == 'd') {//add
			scanf("%d %d %lld", &a, &b, &v);
			add(a, b, v);
		} else if (s[1] == 'e') {//set
			scanf("%d %d %lld", &a, &b, &v);
			set(a, b, v);
		} else if (s[1] == 'u'){//sum
			scanf("%d %d", &a, &b);
			node ans = ask(a, b);
			printf("%lld\n", ans.sumv);
		} else if (s[1] == 'a') {//max
			scanf("%d %d", &a, &b);
			node ans = ask(a, b);
			printf("%lld\n", ans.maxv);
		} else {//min
			scanf("%d %d", &a, &b);
			node ans = ask(a, b);
			printf("%lld\n", ans.minv);
		}
	}
	return 0;
}