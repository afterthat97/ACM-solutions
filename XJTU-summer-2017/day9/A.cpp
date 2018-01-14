#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 25
const long long q[3] = {1, 3, 5};

int n, a[maxn], b[maxn], diff[maxn], tot;
long long all[2000000], pow2[35];

bool find(long long val) {
	int idx = lower_bound(all, all + tot, val) - all;
	if (all[idx] == val) return 1; else return 0;
}

int main() {
	pow2[0] = 1;
	for (int i = 1; i < 30; i++) pow2[i] = pow2[i - 1] * 2;

	while (scanf("%d", &n) == 1) {
		tot = 0;
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
		for (int i = 1; i <= n; i++) diff[i] = a[i] - b[i];
		int mid = n / 2, fst = 1, snd = 1;//[1, mid], [mid + 1, n]
		long long ans = 0;
		for (int i = 0; i < mid; i++) fst *= 3;
		for (int i = 0; i < n - mid; i++) snd *= 3;
		for (int i = 0; i < fst; i++) {
			ans = 0;
			for (int cnt = 1, tmp = i; cnt <= mid; tmp /= 3)
				ans += q[tmp % 3] * diff[cnt++];
			for (int k = 1; k < 30; k++) all[tot++] = pow2[k] - ans;
		}
		sort(all, all + tot);
		bool succ = 0;
		for (int i = 0; i < snd; i++) {
			ans = 0;
			for (int cnt = mid + 1, tmp = i; cnt <= n; tmp /= 3)
				ans += q[tmp % 3] * diff[cnt++];
			if (find(ans)) { succ = 1; break; }
		}
		puts(succ ? "Yes" : "No");
	}
	return 0;
}
