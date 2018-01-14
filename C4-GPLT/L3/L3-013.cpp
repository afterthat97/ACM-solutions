#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	double m, p, ans = 0;
	cin >> m >> p;
	m /= 100;
	p = (100 - p) / 100;
	double dx = 2000 / (9.8 * m);
	while (dx > 1e-8) {
		ans += dx;
		dx *= p;
	}
	printf("%.3f", ans);
	return 0;
}
