#include <iostream>
#include <stdio.h>
#define maxn 1005
#define maxk 105
using namespace std;

int dp[maxn][maxk], n, k;

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i <= n; i++)
        dp[i][0] = dp[i][1] = 1;
    for (int j = 0; j <= k; j++)
        dp[0][j] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 2; j <= k; j++)
            if (i - j >= 0)
                dp[i][j] = dp[i][j - 1] + dp[i - j][j];
            else
                dp[i][j] = dp[i][j - 1];
    printf("%d\n", dp[n][k]);
    return 0;
}
