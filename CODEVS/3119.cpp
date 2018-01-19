#include <iostream>
#include <string>
using namespace std;

const int BLOCK_SIZE = 1000;
string s;
int a[1000], ans[1000];

int cmp(int x[], int y[]) {
	if (x[0] > y[0]) return 1;
	if (x[0] < y[0]) return 0;
	for (int i = a[0]; i >= 1; i--) {
		if (x[i] > y[i]) return 1;
		if (x[i] < y[i]) return 0;
	}
	return 0;
}

int main() {
	cin >> s;
	while (s.size() % 3) s = "0" + s;
	a[0] = s.size() / 3;
	for (int i = 1; i <= a[0]; i++)
		a[a[0]-i+1] = atoi(s.substr(3 * (i - 1), 3).c_str());

	ans[0] = (a[0] >> 1) + 1;
	for (int i = ans[0]; i >= 1; i--) {
		int l = 0, r = 999;
		while (l != r) {
			ans[i] = (l + r + 1) >> 1;

			int ans2[1000] = {};
			for (int m = 1; m <= ans[0]; m++)
				for (int n = 1; n <= ans[0]; n++)
					ans2[m + n - 1] += ans[m] * ans[n];
			ans2[0] = 2 * ans[0] - 1;
			for (int m = 1; m <= ans2[0] - 1; m++) {
				ans2[m + 1] += ans2[m] / BLOCK_SIZE;
				ans2[m] %= BLOCK_SIZE;
			}
			while (ans2[ans2[0]] > BLOCK_SIZE) {
				ans2[ans2[0] + 1] += ans2[ans2[0]] / BLOCK_SIZE;
				ans2[ans2[0]] %= BLOCK_SIZE;
				ans2[0]++;
			}
			while ((ans2[ans2[0]] == 0) && (ans2[0] > 1)) {
				ans2[0]--;
			}
			if (cmp(ans2, a)) r = ans[i]-1;
			else l = ans[i];
		}
		ans[i] = l;
	}
	if ((ans[0] > 1) && (ans[ans[0]] == 0)) ans[0]--;

	cout << ans[ans[0]];
	for (int i = ans[0] - 1; i >= 1; i--) {
		if (ans[i] < 100) cout << 0;
		if (ans[i] < 10) cout << 0;
		cout << ans[i];
	}
	return 0;
}