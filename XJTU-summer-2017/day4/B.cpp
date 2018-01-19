#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#define ll long long
#define add(xx, yy, zz) x[cnt] = xx; y[cnt] = yy; z[cnt] = zz; cnt++;
using namespace std;

ll a[1005][1005], b[1005][1005], sum[1005][1005];
int n, m, q, x[2005], y[2005], z[2005], cnt, limit;

void getsum() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] 
						- sum[i - 1][j - 1] + a[i][j];
}

int main() {
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%lld", &b[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			a[i][j] = b[i][j] - b[i - 1][j] - b[i][j - 1] + b[i - 1][j - 1];

	limit = (int)sqrt(4 * n * m);
	getsum();
	for (int i = 0; i < q; i++) {
		int cho, x1, x2, y1, y2, val;
		scanf("%d", &cho);
		if (cho == 1) {
			scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &val);
			add(x1, y1, val);
			add(x2 + 1, y1, -val);
			add(x1, y2 + 1, -val);
			add(x2 + 1, y2 + 1, val);
			if (cnt >= limit) {
				for (int i = 0; i < cnt; i++) a[x[i]][y[i]] += z[i];
				getsum(); cnt = 0;	
			}
		} else {
			scanf("%d %d", &x1, &y1);
			ll ans = sum[x1][y1];
			for (int i = 0; i < cnt; i++)
				if (x[i] <= x1 && y[i] <= y1)
					ans += z[i];
			printf("%lld\n", ans);
		}
	}	
	return 0;
}
