#include <iostream>
#include <stdio.h>
#define inf 0x7fffffffffffffff
#define ll long long
using namespace std;

ll extgcd(ll a, ll b, ll& x, ll& y) {
	if (b == 0) {
		x = 1; y = 0; return a;
	} else {
		ll r = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
		return r;
	}
}

int main() {
	ll a, b, x1, y1, x2, y2;
	cin >> a >> b;
	extgcd(a, b, x1, y1);
	if (x1 < 0) {
		x2 = x1 + b; y2 = y1 - a;
		swap(x1, x2); swap(y1, y2);
	} else {
		x2 = x1 - b; y2 = y1 + a;
	}
	cout << (-x2 - 1) * a + (-y1 - 1) * b + 1 << endl;
	return 0;
}
