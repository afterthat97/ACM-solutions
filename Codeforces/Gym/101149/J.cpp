#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;

int n, t, b;
ll ans;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		if (t < b) ans += b - t;
		b = t;
	}
	cout << ans + b << endl;
	return 0;
}
