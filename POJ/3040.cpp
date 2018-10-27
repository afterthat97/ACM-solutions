#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#define maxn 25
using namespace std;

struct coin {
    int v, num;
}coins[maxn];

int n, c, ans, cnt[maxn];

bool cmp(const coin& a, const coin& b) {
    return a.v > b.v;
}

int main() {
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &coins[i].v, &coins[i].num);
    sort(coins, coins + n, cmp);
    while (true) {
        memset(cnt, 0, sizeof cnt);
        int tot = c;
        for (int i = 0; i < n; i++) {
            cnt[i] = min(coins[i].num, tot / coins[i].v);
            tot -= cnt[i] * coins[i].v;
            if (tot <= 0) break;
        }
        if (tot > 0)
            for (int i = n - 1; i >= 0; i--)
                if (coins[i].num - cnt[i] > 0) {
                    int t = min(coins[i].num - cnt[i], (int) ceil(tot * 1.0 / coins[i].v));
                    cnt[i] += t;
                    tot -= t * coins[i].v;
                    if (tot <= 0) break;
                }
        if (tot > 0) break;
        int weeks = 0x7fffffff;
        for (int i = 0; i < n; i++)
            if (cnt[i])
                weeks = min(weeks, coins[i].num / cnt[i]);
        for (int i = 0; i < n; i++)
            coins[i].num -= cnt[i] * weeks;
        ans += weeks;
    }
    cout << ans << endl;
    return 0;
}
