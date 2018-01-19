#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
#define maxn 10005
#define MOD 10007
using namespace std;

bool notp[maxn];
int pnum, p[maxn], u[maxn];

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

int n, cnt[maxn];

int main() {
	sieve(maxn);
	while (scanf("%d", &n) == 1) {
		memset(cnt, 0, sizeof cnt);
		for (int i = 0; i < n; i++) {
			int t; scanf("%d", &t);
			for (int j = 1; j * j <= t; j++)
				if (t % j == 0) {
					cnt[j]++;
					if (t / j != j) cnt[t / j]++;
				}
		}
		int ans = 0;
		for (int k = 1; k < maxn; k++) {
			int sum = 0;
			for (int i = 1; i * k < maxn; i++)
				sum = (sum + u[i] * cnt[i * k] * cnt[i * k]) % MOD;
			sum = (sum * k) % MOD;
			ans = (ans + sum * (k - 1)) % MOD;
		}
		cout << ans << endl;
	}
	return 0;
}
