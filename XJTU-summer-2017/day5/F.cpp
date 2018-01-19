#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
long long rule[1 << 17][20], dp[1 << 17];

int main() {
	while (scanf("%d %d", &n, &m) == 2) {
        memset(rule, 0, sizeof rule);
        memset(dp, 0, sizeof dp);
		for (int i = 0; i < m; i++) {
            long long atk;
            int sk, npre, pre = 1;
			scanf("%lld %d %d", &atk, &sk, &npre);
			for (int j = 0; j < npre; j++) {
				int t; scanf("%d", &t);
				pre |= (1 << t);
			}
            for (int i = 1; i < (1 << (n + 1)); i++)
                if ((i & pre) == pre)
                    rule[i][sk] = max(rule[i][sk], atk);
		}
		long long ans = 0;
		for (int i = 1; i < (1 << (n + 1)); i += 2) {
			for (int p = 1; p <= n; p++) 
				if (i & (1 << p)) {//last p
					int j = i - (1 << p);
					dp[i] = max(dp[i], dp[j] + rule[j][p]);
                }
			//	cout << dp[i][p] << endl;
			if (dp[i] > ans) ans = dp[i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}
