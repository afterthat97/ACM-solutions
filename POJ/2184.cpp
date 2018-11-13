#include <iostream>
#include <stdio.h>
#include <cstring>
#define maxn 105
#define maxs 1050
#define offset maxn * maxs
using namespace std;

int s[maxn], f[maxn], dp[2][maxn * maxs * 2];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%d %d", &s[i], &f[i]);

    memset(dp, -0x3f, sizeof dp);
    dp[0][offset] = 0;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < maxn * maxs * 2; j++) 
            if (j - s[i] >= 0 && j - s[i] < maxn * maxs * 2)
                dp[(i + 1) % 2][j] = max(dp[i % 2][j], dp[i % 2][j - s[i]] + f[i]);
            else
                dp[(i + 1) % 2][j] = dp[i % 2][j];
    
    int ans = 0;
    for (int j = 0; j < maxn * maxs; j++)
        if (dp[n % 2][j + offset] >= 0)
            ans = max(ans, j + dp[n % 2][j + offset]);
    cout << ans << endl;
    return 0;
}
