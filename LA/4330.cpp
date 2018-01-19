#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;

double R, H, v;

double V (double h) {
	double r = R;
	double s = sqrt(r * r - h * h);
	double a = acos(h / r) * r * r * r;
	double l = log(h / (r + s)) * h * h * h;
	s = s * r * h * 2;
	return -(l - a + s) * H / R / 3;
}

int main() {
	int T; cin >> T;
	while (T--) {
		cin >> H >> R >> v;	R /= 2;
		double l = 0.0000000001, r = R;
		while (r - l > 0.000000001) {
			double mid = (l + r) / 2;
			if (V(mid) > v)
				l = mid;
			else
				r = mid;
		}
		printf("%.5lf\n", l + R);
	}
	return 0;
}
