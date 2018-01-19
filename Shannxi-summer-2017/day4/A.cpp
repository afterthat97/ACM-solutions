#include <iostream>
#include <stdio.h>
#define ll long long
#define MOD 1000000007
using namespace std;

char str[100005];

ll qpow(ll a, ll k) {//(a^k)%MOD
	ll ans = 1;
	for (; k; k >>= 1) {
		if (k & 1) ans = (ans * a) % MOD;
		a = (a * a) % MOD;
	}
	return ans;
}

int main() {
	while (scanf("%s", str) == 1) {
		ll n = 0;
		for (int i = 0; str[i]; i++)
			n = (n * 10 + str[i] - '0') % (MOD - 1);
		n = (n - 1 + MOD - 1) % (MOD - 1);
		cout << qpow(2, n) << endl;
	}
	return 0;
}
