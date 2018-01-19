#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, l, pos[200005];

int main() {
	int T; cin >> T;
	for (int idx = 1; idx <= T; idx++) {
		scanf("%d %d %d", &n, &m, &l);
		int cnt = 0;
		pos[0] = -l; pos[1] = 0; pos[n + 2] = m;
		for (int i = 1; i <= n; i++) scanf("%d", &pos[i + 1]);
		sort(pos, pos + n + 3);
		for (int i = 1; i <= n + 1;) {
			int j = i;
			while (j <= n + 1 && pos[j + 1] <= pos[i] + l) j++;
			if (j > i) {
				pos[j - 1] = pos[i];
				i = j; cnt++;
				continue;
			}
			int mul = (pos[i + 1] - pos[i]) / (l + 1) - 1;
			int tmp = max(pos[i] + 1, pos[i - 1] + l + 1);
			if (mul > 0) {
				pos[i - 1] = tmp + (mul - 1) * (l + 1);
				pos[i] += mul * (l + 1);
				cnt += mul * 2;
			} else {
				pos[i - 1] = pos[i];
				pos[i] = tmp;
				cnt++;
			}
		}
		printf("Case #%d: %d\n", idx, cnt);
	}
	return 0;
}
