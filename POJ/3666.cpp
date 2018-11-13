#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#define maxn 2050
#define inf 0x3f3f3f3f
using namespace std;

int pos[maxn], dp[maxn];

int get_lis_up(int n, const int* a, int* lis) {
    memset(dp, inf, sizeof dp);

    for (int i = 0; i < n; i++) {
        int idx = upper_bound(dp, dp + n, a[i]) - dp;
        dp[idx] = a[i];
        pos[i] = idx;
    }
    
    int len = lower_bound(dp, dp + n, inf) - dp;
  
    for (int i = n - 1, cnt = len - 1; ~i && ~cnt; i--)
        if (pos[i] == cnt)
            lis[cnt--] = i;
   
    return len;
}

int get_lis_dn(int n, const int* a, int* lis) {
    memset(dp, -1, sizeof dp);

    for (int i = 0; i < n; i++) {
        int idx = upper_bound(dp, dp + n, a[i], greater<int>()) - dp;
        dp[idx] = a[i];
        pos[i] = idx;
    }

    int len = lower_bound(dp, dp + n, -1, greater<int>()) - dp;

    for (int i = n - 1, cnt = len - 1; ~i && ~cnt; i--)
        if (pos[i] == cnt)
            lis[cnt--] = i;
   
    return len;
}

int get_ans(int n, const int* a, int len, const int* lis) {
    int ans = 0, cnt = 0;
    while (cnt <= lis[0])
        ans += abs(a[cnt++] - a[lis[0]]);
    for (int i = 1; i < len; i++)
        while (cnt <= lis[i]) {
            ans += min(abs(a[cnt] - a[lis[i]]), abs(a[cnt] - a[lis[i - 1]]));
            cnt++;
        }
    while (cnt < n)
        ans += abs(a[cnt++] - a[lis[len - 1]]);
    return ans;
}

int a[maxn], lis[maxn], n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int dn_len = get_lis_dn(n, a, lis);
    int dn_ans = get_ans(n, a, dn_len, lis);
    
    int up_len = get_lis_up(n, a, lis);
    int up_ans = get_ans(n, a, up_len, lis);

    cout << min(up_ans, dn_ans) << endl;
    return 0;
}
