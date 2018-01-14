#include <iostream>
#include <stdio.h>
using namespace std;

int eu[10000005];

int eular (int x) {
	if (eu[x]) return eu[x];
	int ans = x;
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0) {
			while (x % i == 0) x /= i;
			ans /= i;
			ans *= (i - 1);
		}
	if (x != 1) { ans /= x; ans *= (x - 1); }
	return eu[x] = ans;
}


int qpow(long long a, int k, int mod) {//(a^k)%MOD
	long long ans = 1;
	for (; k; k >>= 1) {
		if (k & 1) ans = (ans * a) % mod;
		a = (a * a) % mod;
	}
	return ans;
}

int solve(int p) {
	if (p == 1) return 0;
	int k = 0, q = p;
	for (; (q & 1) == 0; q >>= 1) k++;
	if (q == 1) return 0;
	int eq = eular(q);
	return qpow(2, (solve(eq) - k % eq + eq) % eq, q) << k;
}

int k, p;

int main() {
	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		scanf("%d", &p);
		printf("%d\n", solve(p));
	}
	return 0;
}
