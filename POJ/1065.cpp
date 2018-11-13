#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#define maxn 5050
using namespace std;

typedef pair<int, int> item;
item a[maxn];
int dp[maxn];

int main() {
    int T; cin >> T;
    while (T--) {
        int n; scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d %d", &a[i].first, &a[i].second);
        sort(a, a + n);
        memset(dp, -1, sizeof dp);
        for (int i = 0; i < n; i++)
            *lower_bound(dp, dp + n, a[i].second, greater<int>()) = a[i].second;
        printf("%d\n", lower_bound(dp, dp + n, -1, greater<int>()) - dp);
    }
    return 0;
}
