#include <iostream>
#include <stdio.h>
#include <queue>
#define maxn 1005
using namespace std;

int pre[maxn], mid[maxn], suc[maxn], tree[maxn], l[maxn], r[maxn], order[maxn];
int cnt, tmp, n;

void build(int a, int b, int& idx) {
	tree[++idx] = suc[--cnt];
	int now = idx, t = -1;
	if (a == b) { return; }
	for (int i = a; i <= b; i++)
		if (mid[i] == tree[idx]) { t = i; break; }
	if (t < b) {
		r[now] = idx + 1;
		build(t + 1, b, idx);
	}
	if (a < t) {
		l[now] = idx + 1;
		build(a, t - 1, idx);
	}
}

void bfs() {
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int now = q.front(); q.pop();
		order[cnt++] = tree[now];
		if (~l[now]) q.push(l[now]);
		if (~r[now]) q.push(r[now]);
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) scanf("%d", &suc[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &mid[i]);

	memset(l, -1, sizeof l);
	memset(r, -1, sizeof r);
	cnt = n + 1;
	build(1, n, tmp);

	cnt = 0;
	bfs();
	printf("%d", order[0]);
	for (int i = 1; i < cnt; i++) printf(" %d", order[i]);
	return 0;
}
