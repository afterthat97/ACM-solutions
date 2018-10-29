#include <iostream>
#include <stdio.h>
#define maxn 30
#define maxm 2050
using namespace std;

int n, m, cost[maxn], dp[maxm][maxm];
char str[maxm];

int main() {
    scanf("%d %d %s", &n, &m, str);
    for (int i = 0; i < n; i++) {
        char ch; int x, y;
        scanf(" %c %d %d", &ch, &x, &y);
        cost[ch - 'a'] = min(x, y);
    }
    for (int i = m - 1; i >= 0; i--)
        for (int j = i + 1; j < m; j++) {
            dp[i][j] = min(dp[i][j - 1] + cost[str[j] - 'a'], dp[i + 1][j] + cost[str[i] - 'a']);
            if (str[i] == str[j])
                dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
        }
    printf("%d\n", dp[0][m - 1]);
    return 0;
}
