#include <iostream>
#include <stdio.h>
#include <algorithm>
#define ll long long
#define maxn 100005
using namespace std;

struct cow {
    ll t, d;
}a[maxn];

bool cmp(const cow& a, const cow& b) {
    return a.d * b.t > b.d * a.t;
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lld %lld", &a[i].t, &a[i].d);
    sort(a, a + n, cmp);
    ll ans = 0, sumt = 0;
    for (int i = 1; i < n; i++) {
        sumt += a[i - 1].t;
        ans += a[i].d * sumt;
    }
    cout << ans * 2 << endl;
    return 0;
}
