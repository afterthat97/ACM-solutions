#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
#define maxn 65536
using namespace std;

bool notp[maxn];
int pnum, p[maxn], phi[maxn];

void sieve(int n) {
	memset(notp, 0, sizeof notp); pnum = 0;
	for (int i = 2; i < n; i++) {
		if (!notp[i]) {
			p[pnum++] = i;
			phi[i] = i - 1;
		}
		for (int j = 0; j < pnum && i * p[j] < n; j++) {
			int k = i * p[j]; notp[k] = 1;
			if (i % p[j] == 0) {
				phi[k] = phi[i] * p[j];
				break;
			}
			phi[k] = phi[i] * (p[j] - 1);
		}
	}
}

int main() {
	sieve(maxn);
	int n;
	while (scanf("%d", &n) == 1)
		printf("%d\n", phi[phi[n]]);
	return 0;
}
