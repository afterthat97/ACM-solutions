#include <stdio.h>
#include <cstring>
#define uint unsigned int
#define MAXN 60 //max_matrix 10 * 10

struct matrix {
	int n, m;
	uint dat[MAXN][MAXN];//both start from 1
	matrix(int nn = 0, int mm = 0): n(nn), m(mm) {
		memset(dat, 0, sizeof dat);
	}
	uint* operator[](const int i) { return dat[i]; }
};

inline matrix mat_mul(matrix &a, matrix &b) {
	matrix ans(a.n, a.n);
	for (int i = 1; i <= a.n; i++)
		for (int k = 1; k <= a.m; k++)
			for (int j = 1; j <= b.m; j++)
				ans[i][j] = (ans[i][j] + a[i][k] * b[k][j]);
	return ans;
}

matrix qpow_mat(matrix a, long long k) {
	matrix ans(a.n, a.n);
	for (int i = 1; i <= a.n; i++)
		ans[i][i] = 1;
	for (; k; k >>= 1) {
		if (k & 1) ans = mat_mul(ans, a);
		a = mat_mul(a, a);
	}
	return ans;
}

int C[55][55];

void getC() {
	for (int i = 0; i <= 50; i++)
		C[i][i] = C[i][0] = 1;
	for (int i = 2; i <= 50; i++)
		for (int j = 1; j <= i; j++)
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
}

matrix get_base(int k) {
	matrix b(k + 2, k + 2);
	b[1][1] = 1;
	for (int j = 2; j <= k + 2; j++)
		b[1][j] = C[k][j - 2];
	for (int i = 2; i <= k + 2; i++)
		for (int j = i; j <= k + 2; j++)
			b[i][j] = C[k - i + 2][j - i];
	return b;
}

void print(matrix& a) {
	for (int i = 1; i <= a.n; i++) {
		for (int j = 1; j <= a.m; j++)
			printf("%d ", a[i][j]);
		putchar('\n');
	}
}

int main() {
	long long n; int k, T; scanf("%d", &T);
	getC();
	for (int idx = 1; idx <= T; idx++) {
		scanf("%lld %d", &n, &k);	
		matrix a1(k + 2, 1);
		for (int i = 1; i <= a1.n; i++)
			a1[i][1] = 1;
		matrix base = get_base(k);
		matrix mm = qpow_mat(base, n - 1);
		matrix ans = mat_mul(mm, a1);
		printf("Case %d: %u\n", idx, ans[1][1]);
	}
	return 0;
}
