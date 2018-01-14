#include <iostream>
#include <stdio.h>
using namespace std;

int T, x, y, ans;

int gcd(int a, int b) {
	if (a % b == 0) return b;
	else return gcd(b, a % b);
}

void work(int a, int b) {
	if (a < b) swap(a, b);//a>=b
	if (a % (b + 1) == 0) {
		ans++;
		work(a / (1 + b), b);
	}
}

int main() {
	scanf("%d", &T);
	for (int idx = 1; idx <= T; idx++) {
		scanf("%d %d", &x, &y);
		int t = gcd(x, y);
		x = x / t; y = y / t;
		ans = 1;
		work(x, y);
		printf("Case #%d: %d\n", idx, ans);
	}
	return 0;
}
