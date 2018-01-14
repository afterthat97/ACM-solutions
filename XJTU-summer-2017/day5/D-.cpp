#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int n, a[1005][1005];
long long dp[1005][1005];

int main() {
	while (scanf("%d", &n) == 1) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				scanf("%d", &a[i][j]);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
		printf("%lld\n", dp[n][n]);
	}

	return 0;
}
