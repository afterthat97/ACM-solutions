#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

int n, a[5050], fst[5050], lst[5050], dp[5050];
bool flag[5050];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (fst[a[i]]) lst[a[i]] = i; 
		else lst[a[i]] = fst[a[i]] = i;
	}
	for (int st = 1; st <= n; st++) {
		if (fst[a[st]] < st) continue;
		int r = lst[a[st]], sum = 0;
		memset(flag, 0, sizeof flag);
		for (int i = st; i <= r; i++) {
			if (!flag[a[i]]) {
				sum = sum ^ a[i];
				flag[a[i]] = 1;
			}
			if (fst[a[i]] < st) { sum = -99999999; break; }
			if (lst[a[i]] > r) r = lst[a[i]];
		}
		sum += dp[st - 1];
		for (int i = r; i <= n; i++)
			if (dp[i] < sum) dp[i] = sum;
		//cout << st << ',' << r << ':';
		//for (int i = 1; i <= n; i++)
		//	cout << dp[i] << ' '; cout << endl;

	}	
	cout << dp[n] << endl;
	return 0;
}
