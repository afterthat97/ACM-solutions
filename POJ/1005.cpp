#include <iostream>
#include <stdio.h>
#include <cmath>
#define PI (acos(-1.0))
using namespace std;

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		double x, y; cin >> x >> y;
		double r = sqrt(x * x + y * y);
		double area = PI * r * r / 2;
		int ans = (int)ceil(area / 50);
		printf("Property %d: This property will begin eroding in year %d.\n",
				i, ans);
	}
	puts("END OF OUTPUT.");
	return 0;
}
