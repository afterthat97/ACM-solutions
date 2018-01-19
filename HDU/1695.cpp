#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
#define maxn 100005
#define ll long long
using namespace std;

bool notp[maxn];
int pnum, p[maxn], u[maxn], sumu[maxn];

void sieve(int n) {
	pnum = 0; u[1] = 1;
	for (int i = 2; i < n; i++) {
		if (!notp[i]) {
			p[pnum++] = i;
			u[i] = -1;
		}
		for (int j = 0; j < pnum && i * p[j] < n; j++) {
			int k = i * p[j]; notp[k] = 1;
			if (i % p[j] == 0) {
				u[k] = 0; break;
			}
			u[k] = -u[i];
		}
	}
	for (int i = 1; i < n; i++)
		sumu[i] = sumu[i - 1] + u[i];
}

ll tot(int a, int b) {
	if (a > b) swap(a, b);
	ll ans = 0, last = 0;
	for (int i = 1; i <= a; i = last + 1) {
		ll ai = a / i, bi = b / i;
		last = min(a / ai, b / bi);
		ll num = ai * bi - ai * (ai - 1) / 2;
		ans += num * (sumu[last] - sumu[i - 1]);
	}	
	return ans;
}

int main() {
	sieve(maxn);
	int T; cin >> T;
	for (int idx = 1; idx <= T; idx++) {
		ll sum = 0, a, b, c, d, k;
		scanf("%lld %lld %lld %lld %lld", &a, &b, &c, &d, &k);
		if (k == 0) { printf("Case %d: 0\n", idx); continue; }
		a--; c--; a /= k; b /= k; c /= k; d /= k; k = 1;
		printf("Case %d: %lld\n", idx, tot(a, c) + tot(b, d) - tot(a, d) - tot(b, c));
	}
	return 0;
}
