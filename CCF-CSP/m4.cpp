#include <iostream>
using namespace std;

int two[1001];

int main() {
	int n;
	cin >> n;
	int ans = 0;
	int count0 = 1;
	two[0] = 1;
	for (int k = 1; k <= n; k++) {
		count0 = count0 << 1;
		if (count0 > 1000000007)
			count0 %= 1000000007;
		two[k] = count0;
	}

	for (int i = 3; i < n; i++)
		for (int j = i + 1; j <= n; j++) {
			int count = two[n - 3];
			count -= two[n - i - 1];
			if (count < 0)
				count += 1000000007;
			if (count < 0)
				count += 1000000007;
			ans += count;
			if (ans > 1000000007)
				ans %= 1000000007;
		}//1 3

	for (int i = 2; i < n; i++)
		for (int j = i + 1; j <= n; j++) {
			if (i == 2 && j == 3)continue;
			if (i == 2) {
				int count = two[n - i - 1];
				count -= two[n - j];
				if (count < 0)
					count += 1000000007;
				ans += count;
				ans %= 1000000007;
			} else if (j == i + 1) {
				int count = two[n - j + i - 2];
				count -= two[n - j];
				if (count < 0)
					count += 1000000007;
				ans += count;
				ans %= 1000000007;
			} else {
				int count = two[n - 3];
				count -= two[n - j];
				if (count < 0)
					count += 1000000007;
				ans += count;
				if (ans > 1000000007)
					ans %= 1000000007;
			}
		}//3 1

	cout << ans;
	return 0;
}
