#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <stdlib.h>
using namespace std;

int a[100005], n, cost, cnt[3], b[3][3];

int main() {
	while (scanf("%d %*d %d", &n, &cost) == 2) {
		memset(cnt, 0, sizeof cnt);
		memset(b, 0, sizeof b);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			cnt[a[i]]++;
		}
		for (int i = 0; i < cnt[0]; i++)
			b[0][a[i]]++;
		for (int i = cnt[0]; i < cnt[0] + cnt[1]; i++)
			b[1][a[i]]++;
		for (int i = cnt[0] + cnt[1]; i < cnt[0] + cnt[1] + cnt[2]; i++)
			b[2][a[i]]++;
		int ans01 = min(b[0][1], b[1][0]);
		int ans02 = min(b[0][2], b[2][0]);
		int ans12 = min(b[1][2], b[2][1]);
		int sum = 0;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (i != j) sum += b[i][j];
		sum -= ans01 * 2 + ans02 * 2 + ans12 * 2;
		sum = (sum / 3) * 2;
		printf("%d\n", (sum + ans01 + ans02 + ans12) * cost);
	}
    return 0;
}
