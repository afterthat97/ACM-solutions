#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
#define maxn 300050
#define maxq 300050
#define maxnq (maxn + 2 * maxq)
#define maxnode (maxq << 5)
#define ll long long
using namespace std;

int tree[maxnode], lt[maxnode], rt[maxnode], head[maxn], tsize;
vector<ll> newid[maxn];
int n, m, q;

void add(int& k, int l, int r, int idx, int val) {
	if (k == 0) k = ++tsize;
	if (l == r) { tree[k] += val; return; }
	int mid = (l + r) >> 1;
	if (idx <= mid) add(lt[k], l, mid, idx, val);
	else add(rt[k], mid + 1, r, idx, val);
	tree[k] = tree[lt[k]] + tree[rt[k]];
}

int query(int k, int l, int r, int a, int b) {
	if (k == 0 || a > r || b < l) return 0;
	if (a <= l && r <= b) return tree[k];
	int mid = (l + r) >> 1;
	return query(lt[k], l, mid, a, b) + query(rt[k], mid + 1, r, a, b);
}

inline int get(int i, int j) {
	int l = 1, r = maxnq;
	while (l < r) {
		int mid = (l + r) / 2;
		int blank = query(head[i], 1, maxnq, 1, mid);
		if (mid - blank < j) l = mid + 1;
		else r = mid;
	}
	return l;
}

inline ll getid_r(ll rx, ll y) {
	if (y < m) return (rx - 1) * m + y;
	else return newid[rx][y - m];
}

inline ll getid_c(ll x) {
	if (x <= n) return x * m;
	else return newid[n + 1][x - n - 1];
}

int main() {
	scanf("%d %d %d", &n, &m, &q);
	while (q--) {
		ll rx, ry, id;
		scanf("%lld %lld", &rx, &ry);
		if (ry == m) {
			ll x = get(n + 1, rx);
			id = getid_c(x);
			newid[n + 1].push_back(id);
			add(head[n + 1], 1, maxnq, x, 1);
		} else {
			ll x = get(n + 1, rx), y = get(rx, ry);
			id = getid_r(rx, y);
			newid[rx].push_back(getid_c(x));
			newid[n + 1].push_back(id);
			add(head[rx], 1, maxnq, y, 1);
			add(head[n + 1], 1, maxnq, x, 1);
		}
		printf("%lld\n", id);
	}
	return 0;
}
