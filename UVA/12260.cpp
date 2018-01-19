#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#define fst first
#define snd second
using namespace std;

typedef pair<int, int> node;
node *v;

bool cmp(const node& a, const node& b) {
	if (a.fst != b.fst) return a.fst > b.fst;
	return a.snd < b.snd;
}

int dp[1005][1005], cost[1005][1005], n;

int main() {
	int T; cin >> T;
	while (T--) {
		v = new node[1005];
		char name[100];
		int sump = 0;
		memset(dp, 0, sizeof dp);
		memset(cost, 0, sizeof cost);
		scanf("%d %s", &n, name);
		for (int i = 1; i <= n; i++) {
			scanf("%d %d", &v[i].fst, &v[i].snd);
			sump += v[i].fst;
		}
		sort(v + 1, v + n + 1, cmp);
		if (name[0] == 'P') {
			v = v + 1; n--;
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= (i + 1) / 2; j++)
				if (dp[i - 1][j] > dp[i - 1][j - 1] + v[i].snd) {
					dp[i][j] = dp[i - 1][j];
					cost[i][j] = cost[i - 1][j];
				} else if (dp[i - 1][j] == dp[i - 1][j - 1] + v[i].snd) {
					dp[i][j] = dp[i - 1][j];
					cost[i][j] = min(cost[i - 1][j], cost[i - 1][j - 1] + v[i].fst);
				} else {
					dp[i][j] = dp[i - 1][j - 1] + v[i].snd;
					cost[i][j] = cost[i - 1][j - 1] + v[i].fst;
				}
		printf("%d %d\n", sump - cost[n][(n + 1) / 2], dp[n][(n + 1) / 2]);
	}

	return 0;
}
