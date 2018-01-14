#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#define ll long long
#define MAXN 3 //max_matrix 10 * 10
using namespace std;

long long MOD;

struct matrix {
	int n, m;
	ll dat[MAXN][MAXN];//both start from 1
	matrix(int nn = 0, int mm = 0): n(nn), m(mm) {
		memset(dat, 0, sizeof dat);
	}
	ll* operator[](const int i) { return dat[i]; }
};

inline matrix mat_mul(matrix &a, matrix &b) {
	matrix ans(a.n, a.n);
	for (int i = 1; i <= a.n; i++)
		for (int k = 1; k <= a.m; k++)
			for (int j = 1; j <= b.m; j++)
				ans[i][j] = (ans[i][j] + a[i][k] * b[k][j]) % MOD;
	return ans;
}

matrix qpow_mat(matrix a, ll k) {
	matrix ans(a.n, a.n);
	for (int i = 1; i <= a.n; i++)
		ans[i][i] = 1;
	for (; k; k >>= 1) {
		if (k & 1) ans = mat_mul(ans, a);
		a = mat_mul(a, a);
	}
	return ans;
}

int main() {
	ll a, b, n;
	while (scanf("%lld %lld %lld %lld", &a, &b, &n, &MOD) == 4) {	
		matrix base(2, 2);
		base[1][1] = a; base[1][2] = 1;
		base[2][1] = b; base[2][2] = a;
		matrix mm = qpow_mat(base, n - 1);
		ll an = (a * mm[1][1] + mm[2][1]) % MOD;
		ll bn = (a * mm[1][2] + mm[2][2]) % MOD;
		printf("%lld\n", (an << 1) % MOD);
	}
	return 0;
}
