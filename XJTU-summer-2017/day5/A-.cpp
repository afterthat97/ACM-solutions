#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int T, n, c, w[1005], dp[1005][1005];

int main() {
	scanf("%d", &T);
	while (T--) {
		memset(dp, 0, sizeof dp);
		scanf("%d %d", &n, &c);
		for (int i = 1; i <= n; i++)
			scanf("%d", &w[i]);
		for (int i = 0; i <= n; i++)
			dp[i][0] = 1;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= c; j++) {
				if (j >= w[i])
					dp[i][j] = (dp[i - 1][j - w[i]] + dp[i - 1][j]) % 1000000007;
				else
					dp[i][j] = dp[i - 1][j];
			}
		printf("%d\n", dp[n][c]);
	}
	return 0;
}
