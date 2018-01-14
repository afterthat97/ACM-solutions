#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <functional>
#define maxn 1005
using namespace std;

int pre[maxn], mid[maxn], suc[maxn], tree[maxn], l[maxn], r[maxn];
int cnt, n;
bool succ = 1, mirror;

void build(int a, int b, int &idx) {//build pre[a..b]
	tree[++idx] = pre[++cnt];
	int now = idx, t = -1;
	if (a == b) { if (mid[a] != tree[idx]) succ = 0; return; }
	if (!mirror)
		for (int i = a; i <= b; i++)
			if (mid[i] == tree[idx]) { t = i; break; }
	if (mirror)
		for (int i = b; i >= a; i--)
			if (mid[i] == tree[idx]) { t = i; break; }
	if (t == -1) { succ = 0; return; }
	if (t > a) {
		l[now] = idx + 1;
		build(a, t - 1, idx);
	}
	if (t < b) {
		r[now] = idx + 1;
		build(t + 1, b, idx);
	}
}

void suc_order(int p) {
	if (~l[p]) suc_order(l[p]);
	if (~r[p]) suc_order(r[p]);
	suc[++cnt] = tree[p];
}

void output() {
	cnt = 0;
	puts("YES");
	suc_order(1);
	printf("%d", suc[1]);
	for (int i = 2; i <= n; i++) printf(" %d", suc[i]);
}

bool cmp(int a, int b) { return a > b; }

int main() {
	memset(l, -1, sizeof l);
	memset(r, -1, sizeof r);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &pre[i]);
		mid[i] = pre[i];
	}
	sort(mid + 1, mid + n + 1);

	int tmp = 0;
	build(1, n, tmp);
	if (succ) {
		output();
	} else {
		mirror = 1;
		succ = 1;
		sort(mid + 1, mid + n + 1, cmp);
		memset(l, -1, sizeof l);
		memset(r, -1, sizeof r);
		tmp = 0; cnt = 0; build(1, n, tmp);
		if (succ) output();
		else puts("NO");
	}
	return 0;
}
