#include <iostream>
#include <stdio.h>
#include <algorithm>
#define maxn 100050
#define maxx 1000000000
#define maxf 10000
#define maxnode (maxn << 5)
using namespace std;

int tree[maxnode], lt[maxnode], rt[maxnode], head[maxn], tsize;

void add(int& k, int l, int r, int idx, int val) {
	if (k == 0) k = ++tsize;
	if (l == r) {
		tree[k] += val;
		return;
	}
	int mid = (l + r) / 2;
	if (idx <= mid) add(lt[k], l, mid, idx, val);
	else add(rt[k], mid + 1, r, idx, val);
	tree[k] = tree[lt[k]] + tree[rt[k]];
}

int query(int& k, int l, int r, int a, int b) {
	if (k == 0 || a > r || b < l) return 0;
	if (a <= l && r <= b) return tree[k];
	int mid = (l + r) / 2;
	return query(lt[k], l, mid, a, b)
		+ query(rt[k], mid + 1, r, a, b);
}

struct station {
	int x, r, f;
}s[maxn];

int n, diff;

bool cmp(const station& a, const station& b) {
	return a.r > b.r;
}

int main() {
	cin >> n >> diff;
	for (int i = 0; i < n; i++)
		scanf("%d %d %d", &s[i].x, &s[i].r, &s[i].f);
	sort(s, s + n, cmp);
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int x = s[i].x, r = s[i].r, f = s[i].f;
		for (int j = max(1, f - diff); j <= min(maxf, f + diff); j++)
			ans += query(head[j], 1, maxx, max(1, x - r), min(maxx, x + r));
		add(head[f], 1, maxx, x, 1);
	}
	cout << ans << endl;
	return 0;
}
