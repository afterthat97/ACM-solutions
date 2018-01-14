#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

long long area[500000];

int main() {
	for (long long k = 1; k <= 100000; k++) {
		area[4 * k] = 2 * k * k;
		area[4 * k + 1] = 2 * k * k + k - 1;
		area[4 * k + 2] = 2 * k * k + k * 2;
		area[4 * k + 3] = 2 * k * k + k * 3;
	}
	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		long long t;
		scanf("%lld", &t);
		printf("%ld\n", lower_bound(area, area + 500000, t) - area);
	}
	return 0;
}
