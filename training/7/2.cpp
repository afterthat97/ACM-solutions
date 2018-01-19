#include <iostream>
#include <cmath>
#include <stdio.h>
#define ll long long
using namespace std;

ll m = 1;

double qpow(double a, ll k) {
	double ans = 1;
	for (; k; k >>= 1) {
		if (k & 1) ans = (ans * a);
		a = (a * a);
		while (ans > m) ans /= 10;
		while (a > m) a /= 10;
	}
	while (ans > m) ans /= 10;
	while (a > m) a /= 10;
	return ans;
}

int main() {
	ll k, n;
	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		m = 1;
		scanf("%lld %lld", &k, &n);
		while (n--) m *= 10;
		double ans = qpow(2, k);
		printf("%.0lf\n", round(floor(ans)));
	}
	return 0;
}
