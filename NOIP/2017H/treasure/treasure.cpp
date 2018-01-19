#include <iostream>
#include <stdio.h>
#include <cstring>
#define maxn 15
#define inf 0x3f3f3f3f
using namespace std;

int g[maxn][maxn], dp[maxn][1 << maxn], minc[maxn], n, m;

void init() {
	memset(g, 0x3f, sizeof g);
	memset(dp, 0x3f, sizeof dp);
	for (int i = 0; i < maxn; i++)
		dp[1][1 << i] = 0;
}

void solve() {
	for (int i = 1; i <= n; i++)
		for (int x = 0; x < (1 << n); x++) {
			memset(minc, 0x3f, sizeof minc);
			for (int j = 0; j < n; j++)
				if ((x & (1 << j)) == 0) // j not in x
					for (int k = 0; k < n; k++)
						if ((x & (1 << k)) && g[j][k] < inf) // k in x
							minc[j] = min(minc[j], g[j][k] * i);
			int tot = 0, idx[maxn] = {};
			for (int j = 0; j < n; j++)
				if (minc[j] < inf) idx[tot++] = j;
			for (int y = 1; y < (1 << tot); y++) {
				int totc = 0, newx = x;
				for (int k = 0; k < tot; k++)
					if (y & (1 << k)) {
						totc += minc[idx[k]];
						newx |= 1 << idx[k];
					}
				dp[i + 1][newx] = min(dp[i + 1][newx], dp[i][x] + totc);
			}	
		}
}

int main() {
	init();
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int px, py, w;
		cin >> px >> py >> w; px--; py--;
		g[px][py] = g[py][px] = min(g[px][py], w);
	}
	solve();
	int ans = inf;
	for (int i = 2; i <= n; i++)
		ans = min(ans, dp[i][(1 << n) - 1]);
	cout << (ans == inf ? 0 : ans) << endl;
	return 0;
}
