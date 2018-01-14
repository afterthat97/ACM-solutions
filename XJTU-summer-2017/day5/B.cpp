#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

char str[105];
int dp[105][105];

bool match(int a, int b) {
	if (str[a] == '(' && str[b] == ')') return 1;
	if (str[a] == '[' && str[b] == ']') return 1;
	return 0;
}

int main() {
	while (scanf("%s", str) == 1) {
		memset(dp, 0, sizeof dp);
		int len = strlen(str);
		for (int i = 0; i < len; i++)
			dp[i][i] = 1;
		for (int k = 1; k < len; k++) 
			for (int i = 0; i < len - k; i++) {
				int j = i + k;
				dp[i][j] = 0x3f3f3f3f;
				if (match(i, j))
					dp[i][j] = dp[i + 1][j - 1];
				for (int m = i; m < j; m++)
					dp[i][j] = min(dp[i][j], dp[i][m] + dp[m + 1][j]);
			}
		printf("%d\n", dp[0][len - 1]);
	}
	return 0;
}
