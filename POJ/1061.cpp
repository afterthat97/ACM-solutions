#include <iostream>
#include <stdio.h>
#include <algorithm>
#define gcd __gcd
#define ll long long
using namespace std;

//find x and y to satisfy ax + by = gcd(a, b)
//x will <= b, y will <= a
ll extgcd(ll a, ll b, ll& x, ll& y) {
	if (b == 0) {
		x = 1; y = 0; return a;
	} else {
		int r = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
		return r;
	}
}

ll inv(ll a, ll m) {
	ll x, y;
	extgcd(a, m, x, y);
	return (m + x % m) % m;
}

int main() {
	ll x, y, n, m, l;
	while (scanf("%lld %lld %lld %lld %lld", &x, &y, &m, &n, &l) == 5) {
		x %= l; y %= l; m %= l; n %= l;
		if (m < n) { swap(n, m); swap(x, y); }
		if (m == n) { if (x == y) puts("0"); else puts("Impossible"); continue; }
		ll a = m - n, b = y - x;
		ll g = gcd(a, l);
		if (gcd(a, l) == 1)
			printf("%lld\n", ((b * inv(a, l)) % l + l) % l);
		else {
			if (((b % g) + g) % g != 0) puts("Impossible");
			else {
				a /= g; b /= g; l /= g;
				printf("%lld\n", ((b * inv(a, l)) % l + l) % l);
			}
		}
	}
	return 0;
}
