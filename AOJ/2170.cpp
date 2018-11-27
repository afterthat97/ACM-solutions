#include <iostream>
#include <stdio.h>
#include <cstring>
#define ll long long
#define maxn 100005
using namespace std;

pair<char, int> query[maxn];
int par[maxn], flag[maxn], n, q;

int getfa(int x) {
    if (flag[x])
        return x;
    else {
        par[x] = getfa(par[x]);
        return par[x];
    }
}

int main() {
    while (scanf("%d %d", &n, &q) == 2 && n && q) {
        memset(flag, 0, sizeof flag);
        flag[0] = 1; par[0] = 0;
        for (int i = 1; i < n; i++) {
            int p; scanf("%d", &p);
            par[i] = p - 1;
        }
        for (int i = 0; i < q; i++) {
            scanf(" %c %d", &query[i].first, &query[i].second);
            query[i].second--;
            if (query[i].first == 'M')
                flag[query[i].second]++;
        }
        ll ans = 0;
        for (int i = q - 1; ~i; i--)
            if (query[i].first == 'M')
                flag[query[i].second]--;
            else
                ans += getfa(query[i].second) + 1;
        printf("%lld\n", ans);
    }
    return 0;
}
