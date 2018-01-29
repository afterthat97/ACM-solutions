#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int a[1000005];

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		a[i] = x - y;
	}
	sort(a, a + n);
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int idx1 = lower_bound(a, a + n, -a[i]) - a;
		int idx2 = upper_bound(a, a + n, -a[i]) - a;
		if (a[idx1] != -a[i]) continue;
		ans += max(idx2 - max(idx1, i + 1), 0);
	}
	cout << ans << endl;
	return 0;
}
