#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;

ll n, k, p[1005];

double solve() {
	double l = 0, r = 1;
	while (1) {
		double mid = (l + r) / 2.0;
		ll tot = 0;
		for (int i = 0; i < n; i++)
			tot += (ll)floor(p[i] * mid);
		if (tot == k)
			return mid;
		else if (tot > k)
			r = mid;
		else
			l = mid;
	}
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> p[i];
	double val = solve(), ansx = 0, ansy = 1;
	for (int i = 0; i < n; i++) {
		double x = floor(p[i] * val), y = p[i];
		if (x / y > ansx / ansy)
			ansx = x, ansy = y;
	}
	cout << (ll) ansx << '/' << (ll) ansy << endl;
	return 0;
}
