#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAXN 100005
using namespace std;

int n, m, a[MAXN], xx, yy, cc, kth, flr[20][MAXN];
struct node {
	int l, r, f;
}tree[(1 << 18)];

int getint() {  
    int x = 0, flag = 0; char ch = getchar();
    for(; !isdigit(ch); ch = getchar()) 
        if (ch == '-') flag = 1;
    for(; isdigit(ch); ch = getchar()) 
        x = x * 10 + ch - '0'; 
    return flag ? -x : x;
}

void init(int k, int l, int r, int f) {
	if (r - l == 1)
		flr[f][l] = a[l];
	else {
		int lc = k << 1, rc = (k << 1) | 1, mid = (l + r) >> 1;
		init(lc, l, mid, f + 1);
		init(rc, mid, r, f + 1);
		merge(flr[f + 1] + tree[lc].l, flr[f + 1] + tree[lc].r,
			flr[f + 1] + tree[rc].l, flr[f + 1] + tree[rc].r, flr[f] + l);
	}
	tree[k].l = l; tree[k].r = r;
}

int query(int k, int l, int r, int f) {
	if (l >= yy || r <= xx) return 0;
	else if (xx <= l && r <= yy)
		return upper_bound(flr[f] + tree[k].l, flr[f] + tree[k].r, cc) 
			- (flr[f] + tree[k].l);
	else {
		int lc = k << 1, rc = (k << 1) | 1, mid = (l + r) >> 1;
		return query(lc, l, mid, f + 1) + query(rc, mid, r, f + 1);
	}
}

int st_find(int begin, int end, int k) {//segment tree
	xx = begin; yy = end; kth = k;
	int l = -1, r = n - 1;
	while (r - l > 1) {
		int mid = (l + r) >> 1;
		cc = flr[1][mid];
		if (query(1, 0, n, 1) >= kth) r = mid;
		else l = mid;
	}
	return flr[1][r];
}

int main() {
	n = getint(); m = getint();
	for (int i = 0; i < n; i++) a[i] = getint();
	init(1, 0, n, 1);
	for (int i = 0; i < m; i++) {
		int x, y, k;
		x = getint(); y = getint(); k = getint();
		printf("%d\n", st_find(x - 1, y, k));
	}
	return 0;
}
