#include <iostream>
#include <stdio.h>
#include <cstring>
#define maxt 1005
#define maxw 35
using namespace std;

int dp[maxt][maxw], a[maxt], pre_same[maxt], pre_diff[maxt], t, w;

int main() {
    memset(dp, 0xcf, sizeof dp); // -INF
    memset(pre_same, -1, sizeof pre_same);
    memset(pre_diff, -1, sizeof pre_diff);
    scanf("%d %d", &t, &w);
    a[0] = 1;
    for (int i = 1; i <= t; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= t; i++)
        if (a[i] != a[i - 1]) {
            pre_diff[i] = i - 1;
            pre_same[i] = pre_diff[i - 1];
        } else {
            pre_same[i] = i - 1;
            pre_diff[i] = pre_diff[i - 1];
        }

    for (int i = 0; i <= t; i++) {
        for (int j = 0; j <= w; j++) {
            if (i == 0) dp[i][j] = 1;
            if (pre_same[i] != -1)
                dp[i][j] = max(dp[i][j], dp[pre_same[i]][j] + 1);
            if (pre_diff[i] != -1 && j)
                dp[i][j] = max(dp[i][j], dp[pre_diff[i]][j - 1] + 1);
        }
    }
    printf("%d\n", dp[t][w] - 1);
    return 0;
}
