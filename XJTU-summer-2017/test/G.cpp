#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#define maxn 20
#define inf 0x3f3f3f3f
using namespace std;

int n, m,a, dp[1 << 16][maxn], g[maxn][maxn], t[maxn], c[maxn];
bool vis[maxn], valid[1 << 16];

void floyd() {
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (g[i][j] > g[i][k] + g[k][j])
					g[i][j] = g[i][k] + g[k][j];
}

int main() {
	while (scanf("%d %d %d", &n, &m, &a) == 3) {
		memset(g, inf, sizeof g);
		memset(dp, inf, sizeof dp);
		memset(vis, 0, sizeof vis);
		for (int i = 0; i < m; i++) {
			int px, py, w;
			scanf("%d %d %d", &px, &py, &w);
			g[px][py] = g[py][px] = w;
		}
		for (int i = 1; i <= n; i++)
			scanf("%d %d", &c[i], &t[i]);
		n++; g[0][1] = dp[1][0] = 0;
		floyd();
		for (int i = 1; i < (1 << n); i += 2) {
			int sum = 0;
			for (int j = 0; j < n; j++)
				if (i & (1 << j)) sum += c[j];
			if (sum == a)
				for (int j = 0; j < n; j++)
					if (i & (1 << j)) vis[j] = 1;
			valid[i] = (sum == a);
		}
		int ans = inf;
		for (int i = 1; i < (1 << n); i += 2)
			for (int p = 0; p < n; p++) 
				if ((1 << p) & i) {
					if (!vis[p] || dp[i][p] == inf) continue;
					if (valid[i]) ans = min(ans, dp[i][p]);
					for (int q = 0; q < n; q++) {
						if ((1 << q) & i) continue;
						int j = (1 << q) | i;
						dp[j][q] = min(dp[j][q], dp[i][p] + g[p][q] + t[q]);
					}
				}
		printf("%d\n", (ans == inf ? -1 : ans));
	}
	return 0;
}
