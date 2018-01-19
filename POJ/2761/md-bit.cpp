#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAXN 100005
#define MAXM 50005
using namespace std;

int getint() {  
    int x = 0, flag = 0; char ch = getchar();
    for(; !isdigit(ch); ch = getchar()) 
        if (ch == '-') flag = 1;
    for(; isdigit(ch); ch = getchar())
        x = x * 10 + ch - '0'; 
    return flag ? -x : x;
}

int len;
struct node {
	int l, r, k, id, block;
	node() {}
	node(int L, int R, int K, int ID) {
		l = L; r = R; k = K; id = ID;
		block = l / len;
	}
}q[MAXM];

struct dat {
	int val, id;
}raw[MAXN];

bool cmp1(const dat& a, const dat& b) {
	return a.val < b.val;
}

bool cmp2(const node& a, const node& b) {
	if (a.block != b.block) return a.block < b.block;
	return a.r < b.r;
}

int tree[MAXN], map[MAXN], a[MAXN], ans[MAXN], n, m;

inline int sum(int x) {
	int ans = 0;
	for (; x > 0; x -= (x & -x))
		ans += tree[x];
	return ans;
}

inline void add(int x, int val) {
	for (; x <= n; x += (x & -x))
		tree[x] += val;
}

inline int kth(int k) {
	int l = -1, r = n;
	while (r - l > 1) {
		int mid = (l + r) >> 1;
		if (sum(mid) >= k) r = mid;
		else l = mid;
	}
	return r;
}

int main() {
	n = getint(); m = getint();
	len = sqrt(n);
	for (int i = 1; i <= n; i++) {
		raw[i].val = getint();
		raw[i].id = i;
	}
	sort(raw + 1, raw + n + 1, cmp1);
	for (int i = 1; i <= n; i++) {
		a[raw[i].id] = i;
		map[i] = raw[i].val;
	}
	for (int i = 0; i < m; i++) {
		int l, r, k;
		l = getint(); r = getint(); k = getint();
		q[i] = node(l, r, k, i);
	}
	sort(q, q + m, cmp2);
	for (int i = q[0].l; i <= q[0].r; i++)
		add(a[i], 1);
	ans[q[0].id] = map[kth(q[0].k)];
	for (int i = 1; i < m; i++) {
		while (q[i - 1].l < q[i].l) add(a[q[i - 1].l++], -1);
		while (q[i - 1].l > q[i].l) add(a[--q[i - 1].l], 1);
		while (q[i - 1].r < q[i].r) add(a[++q[i - 1].r], 1);
		while (q[i - 1].r > q[i].r) add(a[q[i - 1].r--], -1);
		ans[q[i].id] = map[kth(q[i].k)];
	}
	for (int i = 0; i < m; i++)
		printf("%d\n", ans[i]);
	return 0;
}
