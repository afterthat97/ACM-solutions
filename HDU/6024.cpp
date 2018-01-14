#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#define fst first
#define snd second
#define ll long long
using namespace std;

pair<ll, ll> a[3005];
ll dp[3005], sumd[3005], n;

int main() {
	while (scanf("%lld", &n) == 1) {
		memset(dp, 0x3f, sizeof dp);
		for (int i = 0; i < n; i++)
			scanf("%lld %lld", &a[i].fst, &a[i].snd);
		sort(a, a + n);
		for (int i = 1; i < n; i++)
			a[i].fst -= a[0].fst;
		a[0].fst = a[n].snd = 0;
		for (int i = 1; i < n; i++)
			sumd[i] = sumd[i - 1] + a[i].fst;
		dp[0] = a[0].snd;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < i; j++) {
				ll tot = sumd[i - 1] - sumd[j] - (i - j - 1) * a[j].fst;
				dp[i] = min(dp[i], dp[j] + tot + a[i].snd);
			}
		}
		cout << dp[n] << endl;
	}	
	return 0;
}
