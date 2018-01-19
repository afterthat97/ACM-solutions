#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int n, k, dp[5005];
long long h[5005];

int main() {
	while (scanf("%d %d", &n, &k) == 2) {
		for (int i = 0; i < n; i++)
			scanf("%lld", &h[i]);
		dp[0] = 1;
		for (int i = 1; i < n; i++) {
			dp[i] = 0x3f3f3f3f;
			long long diffy = 0, diffx = 0;
			for (int j = i - 1; j >= max(0, i - k); j--) {
				if ((h[j] - h[i]) * (-diffx) < diffy * (i - j))
					continue;
				diffx = j - i;
				diffy = h[j] - h[i];
				dp[i] = min(dp[i], dp[j] + 1);
			}
		}
		printf("%d\n", dp[n - 1]);
	}

	return 0;
}
