#include <stdio.h>
#include <cstring>
#define ll int
#define MAXN 70 //max_matrix 10 * 10

int MOD;

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
	int n, k;
	while (scanf("%d %d %d", &n, &k, &MOD) == 3 ) {	
		matrix base(2 * n, 2 * n), a1(n, 2 * n);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				scanf("%d", &base[i][j]);
				base[i][j + n] = base[i][j];
				a1[i][j] = base[i][j];
				a1[i][j + n] = base[i][j];
			}
		for (int i = n + 1; i <= 2 * n; i++)
			base[i][i] = 1;
		matrix mm = qpow_mat(base, k - 1);
		matrix ans = mat_mul(a1, mm);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j < n; j++)
				printf("%d ", ans[i][j + n]);
			printf("%d\n", ans[i][n + n]);
		}
	}
	return 0;
}
