#include <iostream>
#include <stdio.h>
#define maxn 1000005
using namespace std;

int dp[maxn], n;

int main() {
    scanf("%d", &n);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++)
        if (i % 2)
            dp[i] = dp[i - 1];
        else
            dp[i] = (dp[i - 1] + dp[i / 2]) % 1000000000;
    printf("%d\n", dp[n]);
    return 0;
}
