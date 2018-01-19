#include <iostream>
#include <cstring>
#define maxn 1005
using namespace std;

int n, ans, a[maxn], dp[maxn];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		dp[i] = 1;
	}
	for (int i = 1; i < n; i++)
		for (int j = 0; j < i; j++)
			if (a[j] < a[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
				ans = max(ans, dp[i]);
			}
	cout << max(ans, 1) << endl;
	return 0;
}
