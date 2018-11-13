#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#define maxn 2005
using namespace std;

int a[maxn], b[maxn], dp[maxn][maxn], n;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    memcpy(b, a, sizeof a);
    sort(b, b + n);
    
    for (int i = 0; i < n; i++) {
        int minn = dp[i][0];
        for (int j = 0; j < n; j++) {
            minn = min(minn, dp[i][j]);
            dp[i + 1][j] = minn + abs(a[i] - b[j]);
        }
    }

    int ans = 0x7fffffff;
    for (int j = 0; j < n; j++)
        ans = min(ans, dp[n][j]);
    cout << ans << endl;
    
    return 0;
}
