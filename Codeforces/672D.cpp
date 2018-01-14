#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;

ll n, k, a[500005], num[500005][2], cnt, sum;


int main() {
	scanf("%I64d %I64d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &a[i]);
	
	sort(a, a + n);
	num[cnt][0] = a[0]; num[cnt][1] = 1; sum = a[0];
	for (int i = 1; i < n; i++) {
		sum += a[i];
		if (a[i] != num[cnt][0]) {
			num[++cnt][0] = a[i];
			num[cnt][1] = 1;
		} else num[cnt][1]++;
	}
	
	ll sum1 = 0, minn = 0, p1 = 0;
	bool explode = 0;
	while (sum1 <= k) {
		p1 += num[minn][1];
		if (minn >= cnt) { minn++; explode = 1; break; }
		sum1 += (num[minn + 1][0] - num[minn][0]) * p1;
		minn++;
	}
	minn--;
	sum1 -= (num[minn + 1][0] - num[minn][0]) * p1;
	ll ans1 = num[minn][0] + (k - sum1) / p1;


	ll sum2 = 0, maxx = cnt, p2 = 0;
	while (sum2 <= k) {
		p2 += num[maxx][1];
		if (maxx == 0) { maxx--; explode = 1; break; }
		sum2 += (num[maxx][0] - num[maxx - 1][0]) * p2;
		maxx--;
	}
	maxx++;
	
	sum2 -= (num[maxx][0] - num[maxx - 1][0]) * p2;
	ll ans2 = num[maxx][0] - (k - sum2) / p2;


	if (explode || ans2 <= ans1) {
		if (sum % n == 0) puts("0"); else puts("1");
	} else {
		cout << ans2 - ans1;
	}
	return 0;
}
