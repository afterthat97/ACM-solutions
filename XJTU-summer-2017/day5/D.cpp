#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int n, a[1005][1005][2], dp[1005][1005][2];

int main() {
	for (int i = 2; i < 1005; i++) {
		dp[i][0][0] = dp[i][0][1] = 0x3f3f3f3f;
		dp[0][i][0] = dp[0][i][1] = 0x3f3f3f3f;
	}
	while (scanf("%d", &n) == 1) {
		memset(a, 0, sizeof a);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				long long tmp;
				scanf("%lld", &tmp);
				while (tmp % 5 == 0) {
					tmp /= 5;
					a[i][j][0]++;
				}
				while ((tmp & 1) == 0) {
					tmp >>= 1;
					a[i][j][1]++;
				}
			}

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				dp[i][j][0] = min(dp[i - 1][j][0], dp[i][j - 1][0]) + a[i][j][0];
				dp[i][j][1] = min(dp[i - 1][j][1], dp[i][j - 1][1]) + a[i][j][1];
			}
		printf("%d\n", min(dp[n][n][0], dp[n][n][1]));
	}

	return 0;
}
