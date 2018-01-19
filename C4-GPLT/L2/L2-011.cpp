#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <queue>
#include <stdlib.h>
using namespace std;

const int maxn = 50;

int pre[maxn], mid[maxn], ans[maxn], tree[maxn], l[maxn], r[maxn];
int n, cnt, tmp;

void build(int a, int b, int &idx) {
	tree[++idx] = pre[++cnt];
	if (a == b) return;
	int now = idx, t = -1;
	for (int i = a; i <= b; i++)
		if (mid[i] == tree[idx]) { t = i; break; }
	if (a < t) {
		l[now] = idx + 1;
		build(a, t - 1, idx);
	}
	if (t < b) {
		r[now] = idx + 1;
		build(t + 1, b, idx);
	}
}

void bfs() {
	queue<int> q;
	q.push(1);
	cnt = 0;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		ans[cnt++] = tree[now];
		if (~r[now]) q.push(r[now]);
		if (~l[now]) q.push(l[now]);
	}
}


int main() {
	memset(l, -1, sizeof l);
	memset(r, -1, sizeof r);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> mid[i];
	for (int i = 1; i <= n; i++) cin >> pre[i];

	build(1, n, tmp);

	bfs();

	printf("%d", ans[0]);
	for (int i = 1; i < n; i++) printf(" %d", ans[i]);
	return 0;
}
