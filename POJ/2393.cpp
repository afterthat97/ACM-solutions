#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;

int main() {
    ll n, s, tot = 0;
    scanf("%lld %lld", &n, &s);
    for (ll i = 0, last = 0x3f3f3f3f; i < n; i++) {
        ll c, y;
        scanf("%lld %lld", &c, &y);
        last = min(last + s, c);
        tot += last * y;
    }
    printf("%lld\n", tot);
    return 0;
}
