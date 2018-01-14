#include <iostream>
#include <cmath>
#include <stdio.h>
#define uint unsigned int
#define ll long long
using namespace std;

ll a[100005], tree[100005];
uint cho, l, r, f[100005], n, m;

inline uint getfa(uint x) {
	return (x == f[x] ? x : getfa(f[x]));
}

inline void add(uint x, ll val) {
	a[l] += val;
	for (; x <= n; x += (x&-x))
		tree[x] += val;
}

inline ll sum(uint x) {
	ll ans = 0;
	for (; x > 0; x -= (x&-x))
		ans += tree[x];
	return ans;
}

int main() {
	scanf("%d", &n);
	for (uint i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		add(i, a[i]);
		f[i] = i;
	}
	scanf("%d", &m);
	for (uint i = 0; i < m; i++) {
		scanf("%d %d %d", &cho, &l, &r);
		if (l > r) swap(l, r);
		if (cho == 1)
			printf("%lld\n", sum(r) - sum(l - 1));
		else
			for (; l <= r; l++) {
				l = f[l] = getfa(l);
				if (l > r) break;
				add(l, floor(sqrt(a[l])) - a[l]);
				if (a[l] == 1) f[l] = l + 1;
			}
	}
	return 0;
}