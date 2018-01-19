#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int T, n, ca, cb, w[1005], dp[1005][1005];

int main() {
	scanf("%d", &T);
	while (T--) {
		memset(dp, 0, sizeof dp);
		scanf("%d %d %d", &n, &ca, &cb);
		for (int i = 1; i <= n; i++)
			scanf("%d", &w[i]);
		for (int i = 1; i <= n; i++)
			for (int j = 0; j <= ca; j++) {
				if (j >= w[i])
					dp[i][j] = min(dp[i - 1][j - w[i]], dp[i - 1][j] + w[i]);
				else
					dp[i][j] = dp[i - 1][j] + w[i];
			}
		if (dp[n][ca] <= cb) puts("Yes"); else puts("No");
	}
	return 0;
}
