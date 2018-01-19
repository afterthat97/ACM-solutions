#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;

ll n, m, a, b, c;

int main() {
	ll T; cin >> T;
	for (ll idx = 1; idx <= T; idx++) {
		scanf("%lld %lld %lld %lld %lld", &n, &m, &a, &b, &c);
		if (a < c) swap(a, c);
		ll maxx = (n - m - 1) * max(a, b);
		maxx += (m / 2) * max(a + c, b + b);
		if (m & 1) maxx += max(b, c);
		ll minn = (m - 1) * min(b, c);
		minn += ((n - m) / 2) * min(a + c, b + b);
		if ((n - m) & 1) minn += min(a, b);
		printf("Case #%lld: %lld %lld\n", idx, maxx, minn);
	}
	return 0;
}
