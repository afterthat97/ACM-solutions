#include <iostream>
#include <stdio.h>
#include <algorithm>
#define maxn 2000005
#define maxm 1005
using namespace std;

struct interval {
    int st, ed, e;
}a[maxm];

bool cmp(const interval& a, const interval& b) {
    return a.ed < b.ed;
}

int n, m, r, dp[maxn];

int main() {
    scanf("%d %d %d", &n, &m, &r);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a[i].st, &a[i].ed, &a[i].e);
        a[i].ed += r;
    }
    sort(a, a + m, cmp);
    int idx = 0;
    for (int i = 1; i <= n + r; i++) {
        while (idx < m && a[idx].ed == i) {
            dp[i] = max(dp[i], dp[a[idx].st] + a[idx].e);
            idx++;
        }
        dp[i] = max(dp[i], dp[i - 1]);
    }
    printf("%d\n", dp[n + r]);
    return 0;
}
