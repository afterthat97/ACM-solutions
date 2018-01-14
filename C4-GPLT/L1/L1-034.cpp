#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int cnt[1005];

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int k; cin >> k;
		for (int j = 0; j < k; j++) {
			int t; cin >> t;
			cnt[t]++;
		}
	}
	int ans = 0, ansj;
	for (int i = 0; i < 1005; i++)
		if (cnt[i] >= ans) {
			ans = cnt[i];
			ansj = i;
		}
	printf("%d %d", ansj, ans);
	return 0;
}
