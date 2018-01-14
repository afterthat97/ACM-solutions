#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int n, a[100005][15], dp[100005][15];

int main() {
	while (scanf("%d", &n) == 1 && n != 0) {
		memset(a, 0, sizeof a);
		memset(dp, 0, sizeof dp);
		int T = 0;
		for (int i = 0; i < n; i++) {
			int x, t;
			scanf("%d %d", &x, &t);
			a[t][x]++;
			T = max(T, t);
		}
		for (int i = 4; i <= 6; i++)
			dp[1][i] = a[1][i];
		for (int i = 2; i <= T; i++)
			for (int j = 0; j <= 10; j++) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + 1]);
				if (j > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
				dp[i][j] += a[i][j];
			}
		int ans = 0;
		for (int i = 0; i <= 10; i++)
			ans = max(ans, dp[T][i]);
		printf("%d\n", ans);
	}
	return 0;
}
