#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;

int main () {
	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		ll t, s, x;
		scanf("%lld %lld %lld", &t, &s, &x);
		x -= t;
		if (x == 1) { puts("NO"); continue; }
		if (x >= 0 && (x % s == 0 || x % s == 1))
				puts("YES");
		else
				puts("NO");
	}
	return 0;
}