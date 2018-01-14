#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int n, m, h[105][105], dp[105][105];

int dfs(int i, int j) {
	if (dp[i][j] > 0) return dp[i][j];
	if (i > 1 && h[i][j] > h[i - 1][j]) dp[i][j] = max(dp[i][j], dfs(i - 1, j));
	if (i < n && h[i][j] > h[i + 1][j]) dp[i][j] = max(dp[i][j], dfs(i + 1, j));
	if (j > 1 && h[i][j] > h[i][j - 1]) dp[i][j] = max(dp[i][j], dfs(i, j - 1));
	if (j < m && h[i][j] > h[i][j + 1]) dp[i][j] = max(dp[i][j], dfs(i, j + 1));
	return ++dp[i][j];
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &h[i][j]);

	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			ans = max(ans, dfs(i, j));

	cout << ans << endl;	
	return 0;
}
