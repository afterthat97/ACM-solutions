#include <stdio.h>
#include <cstring>
#define MAXN 25 //max_matrix 10 * 10
#define MOD 1000

struct matrix {
	int n, m;
	int dat[MAXN][MAXN];//both start from 1
	matrix(int nn = 0, int mm = 0): n(nn), m(mm) {
		memset(dat, 0, sizeof dat);
	}
	int* operator[](const int i) { return dat[i]; }
};

inline matrix mat_mul(matrix &a, matrix &b) {
	matrix ans(a.n, b.m);
	for (int i = 1; i <= a.n; i++)
		for (int k = 1; k <= a.m; k++)
			for (int j = 1; j <= b.m; j++)
				ans[i][j] = (ans[i][j] + a[i][k] * b[k][j]) % MOD;
	return ans;
}

matrix qpow_mat(matrix a, int k) {
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
	int n, m;
	while (scanf("%d %d", &n, &m) == 2 && n) {	
		matrix g(n, n);
		for (int i = 1; i <= m; i++) {
			int px, py;
			scanf("%d %d", &px, &py);
			g[px + 1][py + 1] = 1;
		}
		int q; scanf("%d", &q);
		for (int i = 0; i < q; i++) {
			int px, py, k;
			scanf("%d %d %d", &px, &py, &k);
			matrix mm = qpow_mat(g, k);
			printf("%d\n", mm[px + 1][py + 1]);
		}
	}
	return 0;
}
