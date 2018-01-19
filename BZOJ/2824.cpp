#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
#define maxn 100005
using namespace std;

bool notp[maxn];
int pnum, p[maxn], phi[maxn], u[maxn], d[maxn], fac[maxn];

void sieve(int n) {
	memset(notp, 0, sizeof notp); pnum = 0; fac[1] = u[1] = 1;
	for (int i = 2; i < n; i++) {
		if (!notp[i]) {
			p[pnum++] = i;
			phi[i] = i - 1;
			u[i] = -1;
			fac[i] = 2;
			d[i] = 1;
		}
		for (int j = 0; j < pnum && i * p[j] < n; j++) {
			int k = i * p[j]; notp[k] = 1;
			if (i % p[j] == 0) {
				phi[k] = phi[i] * p[j];
				u[k] = 0;
				fac[k] = fac[i] / (d[i] + 1) * (d[i] + 2);
				d[k] = d[i] + 1;
				break;
			}
			phi[k] = phi[i] * (p[j] - 1);
			u[k] = -u[i];
			fac[k] = fac[i] << 1;
			d[k] = 1;
		}
	}
}

int work(int x) {
	int s = sqrt(x), ans = 0;
	for (int i = 1; i <= s; i++)
		ans += u[i] * (x / (i * i));
	return ans;
}

int main() {
	sieve(maxn);
	int T; cin >> T;
	while (T--) {
		int k; scanf("%d", &k);
		int l = k, r = 2000000000;
		while (l < r) {
			int mid = l + (r - l) / 2;
			if (work(mid) < k)
				l = mid + 1;
			else
				r = mid;
		}
		printf("%d\n", r);
	}
	return 0;
}
