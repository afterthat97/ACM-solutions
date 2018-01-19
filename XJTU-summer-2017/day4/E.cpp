#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#define ll long long
#define maxn 100005
using namespace std;

int n, cnt, tree[maxn * 3];
ll L, R, sum[maxn], all[maxn * 3], ans;

int getid(ll val) {
	return lower_bound(all, all + cnt, val) - all;
}

inline int getsum(int x) {
	int ans = 0;
	for (; x > 0; x -= (x & -x)) ans += tree[x];
	return ans;
}

inline void add(int x, int val) {
	for (; x <= 3 * maxn; x += (x & -x)) tree[x] += val;
}

int main() {
	scanf("%d %lld %lld", &n, &L, &R);
	for (int i = 1; i <= n; i++) {
		ll tmp; scanf("%lld", &tmp);
		sum[i] = sum[i - 1] + tmp;
		all[cnt++] = sum[i];
		all[cnt++] = sum[i] + L;
		all[cnt++] = sum[i] + R;
	}
	all[cnt++] = 0; all[cnt++] = L; all[cnt++] = R;
	sort(all, all + cnt);
	for (int i = n; ~i; i--) {
		int l = getsum(getid(sum[i] + L) - 1);
		int r = getsum(getid(sum[i] + R));
		ans += r - l;
		add(getid(sum[i]), 1);
	}
	cout << ans << endl;
	return 0;
}
