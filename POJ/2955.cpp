#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

char a[105];
int len, dp[105][105];

int match(char c1,char c2) {
	if (c1 == '(' && c2 == ')')return 2;
	if (c1 == '[' && c2 == ']') return 2;
	return 0;
}

void solve() {
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < len - 1; i++)
		dp[1][i] = match(a[i], a[i + 1]);
	for (int i = 0; i < len - 2; i++) {
		dp[2][i] = max(dp[1][i], dp[1][i + 1]);
		if (match(a[i], a[i + 2]))
			dp[2][i] = 2;
	}
	for (int i = 3; i < len; i++) {
		for (int j = 0; j < len - i; j++) {
			for (int k = 0; k < i; k++) {
				if (dp[k][j] + dp[i - k - 1][j + k + 1] > dp[i][j])
					dp[i][j] = dp[k][j] + dp[i - k - 1][j + k + 1];
			}
			if (match(a[j], a[j + i]))
				dp[i][j] = max(dp[i][j], dp[i - 2][j + 1] + 2);
		}
	}
}

int main() {
	while (1) {
		scanf("%s", a);
		if (a[0] == 'e') return 0;
		len = strlen(a);
		solve();
		printf("%d\n", dp[len - 1][0]);
	}
	return 0;
}
