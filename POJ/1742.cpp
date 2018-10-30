#include <iostream>
#include <stdio.h>
#include <cstring>
#define maxn 105
#define maxm 100005
using namespace std;

int dp[maxm], a[maxn], c[maxn], n, m;

int main() {
    while (scanf("%d %d", &n, &m) == 2 && n && m) {
        memset(dp, -1, sizeof dp);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        for (int i = 0; i < n; i++) scanf("%d", &c[i]);
        dp[0] = c[0];
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= m; j++) {
                if (dp[j] >= 0)
                    dp[j] = c[i];
                else if (j < a[i] || dp[j - a[i]] <= 0)
                    dp[j] = -1;
                else
                    dp[j] = dp[j - a[i]] - 1;
            }
        int ans = 0;
        for (int j = 1; j <= m; j++)
            if (dp[j] >= 0)
                ans++;
        printf("%d\n", ans);
    }
    return 0;
}
