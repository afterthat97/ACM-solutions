#include <iostream>
#include <stdio.h>
using namespace std;

long long k;
int n, m, px, py;
long long base;

long long cnt[105][105];

int main() {
	cin >> n >> m >> k >> px >> py;
	if (n == 1) {
		base = k / m;
		k = k % m;
	} else {
		int roundnum = m * (n - 1) * 2;
		base = k / roundnum;
		k = k % roundnum;
	}

	bool ok = 0;
	for (int j = 1; j <= m; j++)
		cnt[1][j] = cnt[n][j] = base;
	for (int i = 2; i < n; i++)
		for (int j = 1; j <= m; j++)
			cnt[i][j] = base << 1;

	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= m; j++) {

			if (k == 0) {
				ok = 1;
				break;
			}
			cnt[i][j]++;
			k--;
		}
		if (ok) break;
	}
	if (!ok)
	for (int i = n; i > 1; i--) {
		for (int j = 1; j <= m; j++) {

			if (k == 0) {
				ok = 1;
				break;
			}
			cnt[i][j]++;
			k--;
		}
		if (ok) break;
	}

	if (n == 1)
		for (int j = 1; j <= m; j++) {
			if (k == 0) break;
			cnt[1][j]++;
			k--;

		}
	long long maxx = 0;
	long long minn = 0x7fffffffffffffff;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (cnt[i][j] > maxx) maxx = cnt[i][j];
			if (cnt[i][j] < minn) minn = cnt[i][j];
		}

	cout << maxx << ' ' << minn << ' ' << cnt[px][py] << endl;
	return 0;
}
