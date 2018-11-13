#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#define maxn 40050
using namespace std;

int dp[maxn];

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        memset(dp, 0x3f, sizeof dp);
        for (int i = 0; i < n; i++) {
            int t; scanf("%d", &t);
            *lower_bound(dp, dp + n, t) = t;
        }
        cout << lower_bound(dp, dp + n, 0x3f3f3f3f) - dp << endl;
    }
    return 0;
}
