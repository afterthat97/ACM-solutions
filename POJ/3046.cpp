#include <iostream>
#include <stdio.h>
#define MOD 1000000
#define maxn 1005
#define maxm 100005
using namespace std;

int n, m, st, ed, dp[2][maxm], c[maxn];

int main() {
    scanf("%d %d %d %d", &n, &m, &st, &ed);
    for (int i = 0; i < m; i++) {
        int t;
        scanf("%d", &t);
        c[t - 1]++;
    }
    dp[0][0] = dp[1][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= m; j++)
            if (j - 1 - c[i] >= 0)
                dp[i % 2][j] = (dp[i % 2][j - 1] 
                        + dp[!(i % 2)][j] 
                        - dp[!(i % 2)][j - 1 - c[i]] + MOD) % MOD;
            else
                dp[i % 2][j] = (dp[i % 2][j - 1]
                        + dp[!(i % 2)][j]) % MOD;
    int ans = 0;
    for (int j = st; j <= ed; j++)
        ans = (ans + dp[(n - 1) % 2][j]) % MOD;
    printf("%d\n", ans);
    return 0;
}
