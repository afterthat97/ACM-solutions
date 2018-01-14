#include <iostream>
#include <stdio.h>
#include <cstring>
#define MOD 999983
#define ll long long
using namespace std;

long long dp[105][105][105];
int n, m;

int main() {
	scanf("%d %d", &n, &m);
	dp[1][m][0] = 1;
	dp[1][m - 1][1] = m;
	dp[1][m - 2][2] = m * (m - 1) / 2;

	if (n == 1) { cout << 1 + m * (m + 1) / 2 << endl; return 0; }
	long long ans = 0;
	for (int i = 2; i <= n; i++)
		for (int a = 0; a <= m; a++)
			for (int b = 0; b <= m; b++) {
				int c = m - a - b; if (c < 0) continue;
				dp[i][a][b] = dp[i - 1][a][b];
				if (a < m && b > 0) dp[i][a][b] += dp[i - 1][a + 1][b - 1] * (a + 1);
				if (b < m && c > 0)	dp[i][a][b] += dp[i - 1][a][b + 1] * (b + 1);
				if (a < m - 1 && b > 1) dp[i][a][b] += dp[i - 1][a + 2][b - 2] * (a + 2) * (a + 1) / 2;
				if (b < m - 1 && c > 1) dp[i][a][b] += dp[i - 1][a][b + 2] * (b + 2) * (b + 1) / 2;
				if (a < m && b < m && c > 0) dp[i][a][b] += dp[i - 1][a + 1][b] * (a + 1) * (b);
				dp[i][a][b] %= MOD;
				if (i == n) ans = (ans + dp[i][a][b]) % MOD;
			}

	cout << ans << endl;
	return 0;
}
