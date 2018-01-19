#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int n, a[1000005];

int main() {
	while (scanf("%d", &n) == 1) {
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		sort(a, a + n);
		int minn = a[0], maxx = a[n - 1], ans = n;
		if (n == 2 || minn == maxx) { puts("0"); continue; }
		for (int i = 0; a[i] == minn; i++) ans--;
		for (int i = n - 1; a[i] == maxx; i--) ans--;
		cout << ans << endl;
	}
	return 0;
}
