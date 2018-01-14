#include <iostream>
#include <stdio.h>
#include <queue>
#include <functional>
#define ll long long
using namespace std;

int n, m;
priority_queue<ll, vector<ll>, greater<ll> > q;

int main() {
	while (scanf("%d %d", &n, &m) == 2) {
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			ll t; scanf("%lld", &t);
			q.push(t);
		}
		while (n >= 2 * m - 1) {
			ll sum = 0;
			for (int i = 0; i < m; i++) { 
				sum += q.top();
				q.pop();
			}
			ans += sum; q.push(sum); n -= m - 1;
		}
		if (n == m) {
			for (int i = 0; i < m; i++) {
				ans += q.top();
				q.pop();
			}
		} else {
			ll sum = 0;
			for (int i = 0; i < n - m + 1; i++) {
				sum += q.top();
				q.pop();
			}
			q.push(sum); ans += sum;
			for (int i = 0; i < m; i++) {
				ans += q.top();
				q.pop();
			}
		}
		cout << ans << endl;
	}
	return 0;
}
