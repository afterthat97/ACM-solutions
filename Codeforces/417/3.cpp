#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

long long a[100005], n, s;
long long p[100005];

int main() {
	cin >> n >> s;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	long long l = 0, r = n + 1;
	long long ans1 = 0, ans2 = 0;
	while (l <= r) {
		long long mid = (l + r) >> 1;
		for (int i = 1; i <= n; i++)
			p[i] = a[i] + i * mid;
		sort(p + 1, p + n + 1);
		long long tot = 0;
		for (int i = 1; i <= mid; i++)
			tot += p[i];
		if (tot > s) r = mid - 1;
		else {
			l = mid + 1;
			if (mid > ans1 && mid <= n) {
			ans1 = mid; ans2 = tot;
			}
		}
	}
	cout << ans1 << ' ' << ans2 << endl;
	return 0;
}
