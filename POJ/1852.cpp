#include <iostream>
#include <stdio.h>
using namespace std;

int len, n;

int main() {
	int T; cin >> T;
	while (T--) {
		scanf("%d %d", &len, &n);
		int ansmin = 0, ansmax = 0;
		for (int i = 0; i < n; i++) {
			int t; scanf("%d", &t);
			ansmin = max(ansmin, min(t, len - t));
			ansmax = max(ansmax, max(t, len - t));
		}
		printf("%d %d\n", ansmin, ansmax);
	}
	return 0;
}
