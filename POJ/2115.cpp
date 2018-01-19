#include <iostream>
#include <stdio.h>
#include <cstring>
#define ll long long

using namespace std;

void exgcd(ll a, ll b, ll &x, ll &y, ll &gcd) {
	if (b == 0) {
		x = 1; y = 0;
		gcd = a;
	} else {
		exgcd(b, a%b, y, x, gcd);
		y -= x*(a / b);
	}
}

int main() {
	ll A, B, C, k;
	while (scanf("%lld %lld %lld %lld", &A, &B, &C, &k) == 4) {
		if (A == 0 && B == 0 && C == 0 && k == 0)break;
		ll a = C,b, c = B - A, gcd, x, y;
		if (c == 0) {
			cout << 0 << endl;
			continue;
		}
		b = (ll)1 << k;
		exgcd(a, b, x, y, gcd);
		if (c%gcd) {
			cout << "FOREVER\n";
		} else {
			cout << (((x*(c / gcd)) % (b / gcd)) + b / gcd) % (b / gcd) << endl;
		}
	}
	return 0;
}
