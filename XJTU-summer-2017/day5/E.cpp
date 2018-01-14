#include <iostream>
#include <stdio.h>
using namespace std;

int n, dp[1000005];

int main() {
	while (scanf("%d", &n) == 1) {
		dp[1] = 1;
		for (int i = 2; i <= n; i++) {
			if ((i & 1) == 0)
				dp[i] = (dp[i >> 1] + dp[i - 1]) % 1000000007;
			else
				dp[i] = dp[i - 1];
		}
		printf("%d\n", dp[n]);
	}

	return 0;
}
