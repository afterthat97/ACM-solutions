#include <stdio.h>
#include <cstring>
#define ll unsigned long long
#define MAXN 3 //max_matrix 10 * 10

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
				ans[i][j] += a[i][k] * b[k][j];
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
	ll n, p, q; int T; scanf("%d\n", &T);
	for (int idx = 1; idx <= T; idx++) {
		scanf("%lld %lld %llu", &p, &q, &n);
		matrix base(2, 2);
		base[1][1] = -q; base[1][2] = p;
		base[2][1] = -p * q; base[2][2] = p * p - q;
		matrix mm = qpow_mat(base, n >> 1);
		if (n & 1)
			printf("Case %d: %llu\n", idx, mm[2][1] * 2 + mm[2][2] * p);
		else 
			printf("Case %d: %llu\n", idx, mm[1][1] * 2 + mm[1][2] * p);
	}
	return 0;
}
