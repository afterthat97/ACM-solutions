#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
#define maxn 200005
#define maxm 1000005
#define MOD 1000000007
#define ll long long
using namespace std;

bool notp[maxm];
int pnum, p[maxm], u[maxm];
ll ans, cnt[maxm], pow2[maxn];

void sieve(int n) {
	memset(notp, 0, sizeof notp); pnum = 0;
	u[1] = 1;
	for (int i = 2; i < n; i++) {
		if (!notp[i]) {
			p[pnum++] = i;
			u[i] = -1;
		}
		for (int j = 0; j < pnum && i * p[j] < n; j++) {
			int k = i * p[j]; notp[k] = 1;
			if (i % p[j] == 0) {
				u[k] = 0;
				break;
			}
			u[k] = -u[i];
		}
	}
}

int main() {
	sieve(maxm);
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {;
		int t; scanf("%d", &t);
		for (int j = 1; j * j <= t; j++)
			if (t % j == 0) {
				cnt[j]++;
				if (j * j != t) cnt[t / j]++;
			}
	}
	pow2[0] = 1;
	for (int i = 1; i < maxn; i++)
		pow2[i] = (pow2[i - 1] << 1) % MOD;
	for (int i = 1; i < maxm; i++)
		cnt[i] = (cnt[i] * pow2[cnt[i] - 1]) % MOD;
	for (int k = 2; k < maxm; k++) {
		ll sum = 0;
		for (int i = 1; i * k < maxm; i++)
			sum = (sum + u[i] * cnt[i * k]) % MOD;
		ans = (ans + sum * k) % MOD;
	}
	cout << ans << endl;
	return 0;
}
