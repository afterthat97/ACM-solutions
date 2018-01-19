#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <stdlib.h>
#include <cmath>
#include <vector>
#define fst first
#define snd second
#define ll long long
using namespace std;

int n, m, _n, tot, tree[300000];
long long cnt[1000005];
typedef pair<int, int> node;

inline void update(int k, int v) {
	k += _n - 1; tree[k] = v;
    for (k >>= 1; k; k >>= 1)
        tree[k] = __gcd(tree[k << 1], tree[k << 1 | 1]);
}

int lowerbound(int k, int l, int r, int a, int b, int v) {
	if (r < a || l > b || tree[k] % v == 0) return 0;
	if (l == r) return l;
	int mid = (l + r) >> 1, lt = k << 1, rt = k << 1 | 1;
	int rans = lowerbound(rt, mid + 1, r, a, b, v);
	return rans ? rans : lowerbound(lt, l, mid, a, b, v);
}

int upperbound(int k, int l, int r, int a, int b, int v) {
	if (r < a || l > b || tree[k] % v == 0) return n + 1;
	if (l == r) return l;
	int mid = (l + r) >> 1, lt = k << 1, rt = k << 1 | 1;
	int lans = upperbound(lt, l, mid, a, b, v);
	return lans < n + 1 ? lans : upperbound(rt, mid + 1, r, a, b, v);
}

void work(int k, int flag, int init = 0) {
	vector<node> l, r;
	int v = tree[k + _n - 1];
	for (int pos = k, pre = k; pos >= 1; pre = pos) {
		pos = lowerbound(1, 1, _n, 1, k, v);
		l.push_back(node(pre - pos, v));
		v = __gcd(v, tree[pos + _n - 1]);
	}
	v = tree[k + _n - 1];
	for (int pos = k, pre = k; pos <= n; pre = pos) {
		pos = upperbound(1, 1, _n, k, n, v);
		r.push_back(node(pos - pre, v));
		if (init) { r[0].fst = 1; break; }
		v = __gcd(v, tree[pos + _n - 1]);
	}
	for (int i = 0; i < l.size(); i++)
		for (int j = 0; j < r.size(); j++) {
			int all = __gcd(l[i].snd, r[j].snd);
			if (cnt[all] == 0) tot++;
			cnt[all] += flag * l[i].fst * r[j].fst;
			if (cnt[all] == 0) tot--;
		}
}

void init() {
	for (_n = 1; _n < n;) _n <<= 1;
    memset(tree, 0, sizeof tree);
	for (int i = _n; i < _n + n; i++) scanf("%d", &tree[i]);
	for (int i = _n + n; i < 2 * _n; i++) tree[i] = tree[i - 1];
	for (int p = _n >> 1; p; p >>= 1)
		for (int i = p; i < (p << 1); i++)
			tree[i] = __gcd(tree[i << 1], tree[i << 1 | 1]);
	for (int i = 1; i <= n; i++) work(i, 1, 1);
}

int main() {
	int T; scanf("%d", &T);
	for (int idx = 1; idx <= T; idx++) {
        memset(cnt, 0, sizeof cnt); tot = 0;
        scanf("%d %d", &n, &m);
		printf("Case #%d:\n", idx);
		init();
		for (int i = 0; i < m; i++) {
			int k, v;
			scanf("%d %d", &k, &v);
			work(k, -1); update(k, v); work(k, 1);
			printf("%d\n", tot);
		}
	}
	return 0;
}
