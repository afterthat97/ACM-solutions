#include <iostream>
#include <stdio.h>
#define MAXN 100005
#define ll long long
using namespace std;

ll tree[2][30][MAXN], n, a[MAXN], tot;

ll sum(ll x, ll idx, ll z) {
    ll ans = 0;
    for (; x > 0; x -= (x & -x))
        ans += tree[z][idx][x];
    return ans;
}

void add(ll x, ll val, ll idx, ll z) {
    for (; x <= MAXN - 1; x += (x & -x))
        tree[z][idx][x] += val;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    for (int i = n - 1; ~i; i--) {
        for (ll t = a[i], cnt = 0; cnt < 30; cnt++, t >>= 1)
            if (t & 1) {
                tot += sum(a[i], cnt, 0) * ((ll)1 << cnt);
                add(a[i], 1, cnt, 1);
            } else {
                tot += sum(a[i], cnt, 1) * ((ll)1 << cnt);
                add(a[i], 1, cnt, 0);
            }
    }
    cout << tot << endl;
    return 0;
}
