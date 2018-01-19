#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
#define maxn 1000005
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

int main() {
	sieve(maxn);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		long long sum = 3;
		for (long long i = 1; i <= n; i++)
			sum += u[i] * (n / i) * (n / i) * ((n / i) + 3);
		cout << sum << endl;
	}
	return 0;
}
