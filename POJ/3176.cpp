#include <iostream>
#include <stdio.h>
using namespace std;

int n, a[400][400];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            scanf("%d", &a[i][j]);
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i; j++)
            a[i][j] += max(a[i - 1][j], a[i - 1][j - 1]);
    int ans = 0;
    for (int j = 1; j <= n; j++)
        ans = max(ans, a[n][j]);
    printf("%d\n", ans);
    return 0;
}
