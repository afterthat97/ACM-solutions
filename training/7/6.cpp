#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;

int n;
ll ans;
int cnt[10000009];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		if (i & 1) cnt[i + 1] = i - 1;
		else cnt[i + 1] = i;
	}
	cnt[2] = 1;
	if (n == 0) { puts("1"); return 0; }
	for (int i = 3; i <= n << 1; i++)
		for (int j = i << 1; j <= n; j += i)
			cnt[j] -= cnt[i];
	for (int i = 0; i <= n; i++) ans += cnt[i];
	ans *= 6; ans += 7;
	printf("%lld\n", ans);
	return 0;
}
