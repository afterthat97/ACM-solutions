#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
#define maxn 100005
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
