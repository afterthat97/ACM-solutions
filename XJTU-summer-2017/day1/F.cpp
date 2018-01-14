#include <stdio.h>
#include <cstring>
#define ll long long
#define MAXN 10 //max_matrix 10 * 10
#define MOD 1000000007

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

int a, b, c, t;
ll n;

int main() {
	while (scanf("%d %d %d %d %lld", &a, &b, &c, &t, &n) == 5) {
		matrix base(3, 3);
		base[1][1] = c;		base[1][2] = b;		base[1][3] = a;
		base[2][1] = a*c;	base[2][2] = a*b+c;	base[2][3] = a*a+b;
		base[3][1] = c*a*a + b*c;
		base[3][2] = a*a*b + a*c + b*b;
		base[3][3] = a*a*a + 2*a*b + c;
		long long nn = (n - 1) / 3;
		matrix mm = qpow_mat(base, nn);
		ll ans = 0;
		for (int i = 1; i <= 3; i++) ans += mm[(n - 1) % 3 + 1][i];
		ans = (ans * t) % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}
