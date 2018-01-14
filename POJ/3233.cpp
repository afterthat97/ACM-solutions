#include <iostream>
#include <stdio.h>
#include <cstring>
#define maxn 32
#define read(i) scanf("%d", &i);
using namespace std;

int n, m, k;

struct mat {
	int dat[maxn][maxn];
	mat() {
		memset(dat, 0, sizeof(dat));
	}
};

mat operator + (const mat& a, const mat& b) {
	mat ans;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			ans.dat[i][j] = a.dat[i][j] + b.dat[i][j];
			ans.dat[i][j] %= m;
		}
	return ans;
}

mat operator * (const mat& a, const mat& b) {
	mat ans;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++) {
				ans.dat[i][j] += a.dat[i][k] * b.dat[k][j];
				ans.dat[i][j] %= m;
			}
	return ans;
}

mat power(mat a, int k) {
	if (k == 1)
		return a;
	mat ans;
	for (int i = 1; i <= n; i++)
		ans.dat[i][i] = 1;
	while (k) {
		if (k & 1)
			ans = ans * a;
		k >>= 1;
		a = a*a;
	}
	return ans;
}

mat sum(mat a, int k) {
	if (k == 1)
		return a;
	mat ans;
	for (int i = 1; i <= n; i++)
		ans.dat[i][i] = 1;
	mat temp = power(a, k >> 1);
	ans = ans + temp;
	ans = ans*sum(a, k >> 1);
	if (k & 1)
		ans = ans + temp*temp*a;
	return ans;
}

int main() {
	mat a;
	read(n)read(k)read(m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			read(a.dat[i][j]);
	a = sum(a, k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < n; j++)
			printf("%d ", a.dat[i][j]);
		printf("%d\n", a.dat[i][n]);
	}
	return 0;
}
