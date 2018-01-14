#include <stdio.h>
#include <cstring>
#define ll long long
#define MOD 1000000007

ll qpow(ll a, ll k) {//(a^k)%MOD
	ll ans = 1;
	for (; k; k >>= 1) {
		if (k & 1) ans = (ans * a) % MOD;
		a = (a * a) % MOD;
	}
	return ans;
}

ll div(ll x, ll y) {
	return (x * qpow(y, MOD - 2)) % MOD;
}

ll x, n, p;

int main() {
	while (scanf("%lld %lld %lld", &x, &n, &p) == 3 && x) {
		if (x == 1) { puts("1"); continue; }
		ll y = qpow(x, n) - 1;
		if (y == -1) y += MOD;
		x = div(y, x - 1);
		printf("%lld\n", qpow(x, p));
	}
	return 0;
}
