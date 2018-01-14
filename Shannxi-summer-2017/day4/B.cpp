#include <iostream>
#include <stdio.h>
#include <cstring>
#define ll long long
using namespace std;

char str[1000005];
ll a, b, c, ec;

ll eular (ll x) {
	ll ans = x;
	for (ll i = 2; i * i <= x; i++)
		if (x % i == 0) {
			while (x % i == 0) x /= i;
			ans /= i;
			ans *= (i - 1);
		}
	if (x != 1) { ans /= x; ans *= (x - 1); }
	return ans;
}

ll qpow(ll a, ll k) {//(a^k)%MOD
	ll ans = 1;
	for (; k; k >>= 1) {
		if (k & 1) ans = (ans * a) % c;
		a = (a * a) % c;
	}
	return ans;
}


int main() {
	while (scanf("%lld %s %lld", &a, str, &c) == 3) {
		ec = eular(c);
		b = 0;
		for (int i = 0; str[i]; i++)
			b = (b * 10 + str[i] - '0') % ec;
		printf("%lld\n", c == 1 ? 0 : qpow(a, b));
	}
	return 0;
}
