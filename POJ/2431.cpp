#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, less<int> > q;
int n, a[1000005], len, p;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, t; cin >> x >> t;
		a[x] += t;
	}
	cin >> len >> p;
	int ans = 0;
	for (int i = len - 1; i; i--) {
		if (a[i] > 0) q.push(a[i]);
		if (--p == 0) {
			if (q.empty()) { cout << -1; return 0; }
			p += q.top(); q.pop(); ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
