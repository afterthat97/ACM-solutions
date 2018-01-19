#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int T; cin >> T;
	for (int idx = 1; idx <= T; idx++) {
		printf("Case %d:\n", idx);
		int n; scanf("%d", &n);
		int ans = -0x3f3f3f3f, ans1, ans2, st, ed, b = ans;
		for (int i = 1; i <= n; i++) {
			int t; scanf("%d", &t);
			if (b < 0) {
				st = ed = i;
				b = t;
			} else {
				ed = i;
				b += t;
			}
			if (b > ans) {
				ans = b;
				ans1 = st;
				ans2 = ed;
			}
		}
		printf("%d %d %d\n", ans, ans1, ans2);
		if (idx < T) puts("");
	}

	return 0;
}
