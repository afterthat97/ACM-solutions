#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int num[7], dp[7][20000 * 6], idx;

int main() {
	while (1) {
		if (idx) puts("");
		int sum = 0;
		for (int i = 1; i <= 6; i++) {
			cin >> num[i];
			sum += num[i] * i;
		}
		if (sum == 0) return 0;
		printf("Collection #%d:\n", ++idx);
		if (sum & 1) { puts("Can't be divided."); continue; }
		memset(dp, -1, sizeof dp);
		sum /= 2; dp[0][0] = 0;
		for (int i = 1; i <= 6; i++)
			for (int j = 0; j <= sum; j++) {
				if (dp[i - 1][j] >= 0)
					dp[i][j] = num[i];
				else if (i > j || dp[i][j - i] == -1)
					dp[i][j] = -1;
				else
					dp[i][j] = dp[i][j - i] - 1;
			}
		if (dp[6][sum] >= 0)
			puts("Can be divided.");
		else
			puts("Can't be divided.");
	}

	return 0;
}
