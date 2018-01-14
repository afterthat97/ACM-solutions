#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int a[1005], b[1005], n;


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		char t;
		cin >> t;
		a[i] = t - '0';
	}
	for (int i = 0; i < n; i++) {
		char t;
		cin >> t;
		b[i] = t - '0';
	}
	sort(a, a + n); sort(b, b + n);

	int j = 0, ans1 = 0, ans2 = 0;
	for (int i = 0; i < n; i++) {
		if (b[i] >= a[j]) {
			ans1++;
			j++;
		}
	}
	j = 0;
	for (int i = 0; i < n; i++) {
		if (b[i] > a[j]) {
			ans2++;
			j++;
		}
	}
	cout << n - ans1 << endl << ans2 << endl;
	return 0;
}
