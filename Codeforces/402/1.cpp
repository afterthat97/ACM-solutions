#include <iostream>
#include <stdio.h>
using namespace std;

int n;
int a[105], b[105];
int cnt[6], cnta[6];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		cnt[t]++;
		cnta[t]++;
	}
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		cnt[t]++;
	}
	for (int i = 1; i < 6; i++)
		if (cnt[i] % 2 == 1) {
			cout << -1 << endl;
			return 0;
		}

	int ans = 0;
	for (int i = 1; i < 6; i++) {
		if (cnta[i] < cnt[i] / 2)
			ans += cnt[i]/2 - cnta[i];
	}

	cout << ans << endl;
	return 0;
}
