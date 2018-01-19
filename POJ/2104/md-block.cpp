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

struct dat {
	int val, id;
}raw[MAXN];

bool cmp1(const dat& a, const dat& b) { return a.val < b.val; }

int len;
struct node {
	int l, r, k, id, b;
	node() {}
	node(int L, int R, int K, int ID) {
		l = L; r = R; k = K; id = ID; b = l / len;
	}
}q[MAXM];

bool cmp2(const node& a, const node& b) {
	if (a.b != b.b) return a.b < b.b;
	return a.r < b.r;
}

int map[MAXN], a[MAXN], ans[MAXN], num[MAXN], bnum[MAXN], n, m;

inline void inc(int x) { ++num[x], ++bnum[x / len]; }
inline void dec(int x) { --num[x], --bnum[x / len]; }

inline int kth(int k) {
    int cnt = 0;
	for(int i = 0; ; i++) {
        if (cnt + bnum[i] >= k)
            for(int j = i * len; ; j++) {
				cnt += num[j];
				if (cnt >= k) return j;
			}
		cnt += bnum[i];
    }
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
	for (int i = q[0].l; i <= q[0].r; i++) inc(a[i]);
	ans[q[0].id] = map[kth(q[0].k)];
	for (int i = 1; i < m; ++i) {
		for (int j = q[i - 1].l; j < q[i].l; ++j) dec(a[j]);
		for (int j = q[i].l; j < q[i - 1].l; ++j) inc(a[j]);
		for (int j = q[i - 1].r; j < q[i].r; ++j) inc(a[j + 1]);
		for (int j = q[i].r; j < q[i - 1].r; ++j) dec(a[j + 1]);
		ans[q[i].id] = map[kth(q[i].k)];
	}
	for (int i = 0; i < m; i++)
		printf("%d\n", ans[i]);
	return 0;
}
