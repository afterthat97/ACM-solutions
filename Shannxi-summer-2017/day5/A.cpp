#include <stdio.h>
#include <cstring>
#define ll long long
#define MAXN 3 //max_matrix 10 * 10
#define MOD 7

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
		for (int j = 1; j <= b.m; j++)
			for (int k = 1; k <= a.m; k++)
				ans[i][j] = (ans[i][j] + a[i][k] * b[k][j]) % MOD;
	return ans;
}

matrix qpow_mat(matrix a, ll k) {
	matrix ans(a.n, a.n);
	for (int i = 1; i <= a.n; i++) ans[i][i] = 1;
	for (; k; k >>= 1) {
		if (k & 1) ans = mat_mul(ans, a);
		a = mat_mul(a, a);
	}
	return ans;
}

int main() {
	int n, a, b; 
	while (scanf("%d %d %d", &a, &b, &n) == 3 && a && b && n) {
		matrix base(2, 2);
		base[1][1] = b; base[1][2] = a;
		base[2][1] = a * b; base[2][2] = a * a + b;
		int nn = (n - 1) / 2;
		matrix mm = qpow_mat(base, nn);
		if (n & 1) 
			printf("%lld\n", (mm[1][1] + mm[1][2]) % MOD);
		else 
			printf("%lld\n", (mm[2][1] + mm[2][2]) % MOD);
	}
	return 0;
}
