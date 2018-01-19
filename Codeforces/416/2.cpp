//find the Kth smallest element, k starts from 1, [begin, end)
//POJ 2104
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAXN 100005
using namespace std;

int n, m, a[MAXN];

//init: nlogn; find: (logn)^3
int tmp[MAXN], xx, yy, cc, kth;//[x, y], <= c
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
	if (k == 1) {
		memcpy(tmp, a, sizeof(a));
		sort(tmp, tmp + n);
	}
}

int query(int k, int l, int r) {
	if (l >= yy || r <= xx) return 0;
	else if (xx <= l && r <= yy)
		return upper_bound(tree[k].begin(), tree[k].end(), cc) - tree[k].begin();
	else {
		int lc = k << 1, rc = (k << 1) + 1;
		return query(lc, l, (l + r) >> 1) + query(rc, (l + r) >> 1, r);
	}
}

int st_find(int begin, int end, int k) {//segment tree
	xx = begin; yy = end; kth = k;
	int l = -1, r = n - 1;
	while (r - l > 1) {
		int mid = (l + r) >> 1;
		cc = tmp[mid];
		if (query(1, 0, n) >= kth) r = mid;
		else l = mid;
	}
	return tmp[r];
}


int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	init(1, 0, n);
	for (int i = 0; i < m; i++) {
		int x, y, k;
		scanf("%d %d %d", &x, &y, &k);
		if (a[k - 1] == st_find(x - 1, y, k - x + 1)) puts("Yes");
		else puts("No");
	}
	return 0;
}
