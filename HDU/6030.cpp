#include <stdio.h>
#include <cstring>
#define ll long long
#define MAXN 4
const long long MOD = 1000000007;

struct matrix {
	int n, m;
	ll dat[MAXN][MAXN];//both start from 1
	matrix(int nn = 0, int mm = 0): n(nn), m(mm) {
		memset(dat, 0, sizeof dat);
		for (int i = 1; i <= n; i++) dat[i][i] = 1;
	}
	ll* operator[](const int i) { return dat[i]; }
};

inline matrix mat_mul(matrix &a, matrix &b) {
	matrix ans(a.n, a.n);
	for (int i = 1; i <= a.n; i++)
		for (int j = 1; j <= b.m; j++) {
			ll sum = 0;
			for (int k = 1; k <= a.m; k++)
				sum = (sum + a[i][k] * b[k][j]) % MOD;
			ans[i][j] = sum;
		}
	return ans;
}

matrix qpow_mat(matrix a, ll k) {
	matrix ans(a.n, a.n);
	for (; k; k >>= 1) {
		if (k & 1) ans = mat_mul(ans, a);
		a = mat_mul(a, a);
	}
	return ans;
}

int main() {
	int T; scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		ll n; scanf("%lld", &n);
		matrix base(3, 3);
		base[1][1] = 2; base[1][2] = 1; base[1][3] = 1;
		base[2][1] = 1; base[2][2] = 1; base[2][3] = 1;
		base[3][1] = 1; base[3][2] = 0; base[3][3] = 1;
		ll nn = (n - 1) / 3;
		matrix mm = qpow_mat(base, nn);
		if (n % 3 == 0) 
			printf("%lld\n", (4 * mm[1][1] + 3 * mm[1][2] + 2 * mm[1][3]) % MOD);
		else if (n % 3 == 2)
			printf("%lld\n", (4 * mm[2][1] + 3 * mm[2][2] + 2 * mm[2][3]) % MOD);
		else
			printf("%lld\n", (4 * mm[3][1] + 3 * mm[3][2] + 2 * mm[3][3]) % MOD);
	}
	return 0;
}
