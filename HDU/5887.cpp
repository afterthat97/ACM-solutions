#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#define fst first
#define snd second
#define ll long long
using namespace std;

typedef pair<ll, ll> item;
bool cmp(const item& a, const item& b) { return a > b; }

item a[105];
int n;
ll W, ans, sum[105];

void dfs(int idx, ll w, ll v) {
	ans = max(ans, v);
	if (v + sum[idx] <= ans || idx == n) return;
	if (w + a[idx].fst <= W)
		dfs(idx + 1, w + a[idx].fst, v + a[idx].snd);
	dfs(idx + 1, w, v);
}

int main() {
	while (scanf("%d %lld", &n, &W) == 2) {
		for (int i = 0; i < n; i++) {
			scanf("%lld %lld", &a[i].fst, &a[i].snd);
			if (a[i].fst > W) { i--; n--; }
		}
		sort(a, a + n, cmp);
		sum[n] = ans = 0;
		for (int i = n - 1; ~i; i--)
			sum[i] = sum[i + 1] + a[i].snd;
		dfs(0, 0, 0);
		printf("%lld\n", ans);
	}
	return 0;
}
