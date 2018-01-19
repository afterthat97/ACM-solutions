#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#define gcd __gcd
#define ll long long
using namespace std;

ll c, w1, w2, h1, h2, ans, rest;

int main() {
	cin >> c >> h1 >> h2 >> w1 >> w2;
	if (w1 < w2) { swap(w1, w2); swap(h1, h2); }
	ll lcm = w1 * w2 / gcd(w1, w2);
	ll get1 = (lcm / w1) * h1, get2 = (lcm / w2) * h2;
	if (c > lcm * 2) {
		ll num = c / lcm - 2;
		c -= num * lcm;
		ans += num * max(get1, get2);
	}
	for (ll i = 0; i * w1 <= c; i++) {
		ll j = (c - i * w1) / w2;
		rest = max(h1 * i + h2 * j, rest);
	}
	cout << ans + rest << endl;
	return 0;
}
