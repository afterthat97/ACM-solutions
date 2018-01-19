#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAXN 100005
using namespace std;

int n, m, a[MAXN], x, y, c, kth;//[x, y], <= c
vector<int> tree[(1 << 18)];

void init(int k, int l, int r) {
	if (r - l == 1)
		tree[k].push_back(a[l]);
	else {
		int lc = k << 1, rc = (k << 1) + 1;
		init(lc, l, (l + r) >> 1);
		init(rc, (l + r) >> 1, r);
		tree[k].resize(r - l);
		merge(tree[lc].begin(), tree[lc].end(), tree[rc].begin(), tree[rc].end(), tree[k].begin());
	}
}

int query(int k, int l, int r) {
	if (l >= y || r <= x) return 0;
	else if (x <= l && r <= y)
		return upper_bound(tree[k].begin(), tree[k].end(), c) - tree[k].begin();
	else {
		int lc = k << 1, rc = (k << 1) + 1;
		return query(lc, l, (l + r) >> 1) + query(rc, (l + r) >> 1, r);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	init(1, 0, n);
	sort(a, a + n);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &x, &y, &kth);
		int l = -1, r = n - 1; x--;
		while (r - l > 1) {
			int mid = (l + r) >> 1;
			c = a[mid];
			if (query(1, 0, n) >= kth) r = mid;
			else l = mid;
		}
		printf("%d\n", a[r]);
	}
	return 0;
}
