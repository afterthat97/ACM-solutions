#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#define maxn 405
#define maxa 40050
using namespace std;

struct block {
    int h, a, c;
}b[maxn];

int dp[maxn][maxa];

bool cmp(const block& x, const block& y) {
    return x.a < y.a;
}


int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%d %d %d", &b[i].h, &b[i].a, &b[i].c);

    sort(b, b + n, cmp);

    memset(dp, -1, sizeof dp);
    for (int i = 0; i < n; i++)
        dp[i][0] = b[i].c;
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= b[i].a; j++)
            if (i && dp[i - 1][j] >= 0)
                dp[i][j] = b[i].c;
            else if (j - b[i].h >= 0)
                dp[i][j] = dp[i][j - b[i].h] - 1;
    
    int ans = 0;
    for (int j = 0; j < maxa; j++)
        if (dp[n - 1][j] >= 0)
            ans = j;
    cout << ans << endl;
    return 0;
}
