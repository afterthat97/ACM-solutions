#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

priority_queue<long long, vector<long long>, greater<long long> > q;
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long t; cin >> t;
		q.push(t);
	}
	long long ans = 0;
	while (q.size() > 1) {
		long long s1 = q.top(); q.pop();
		long long s2 = q.top(); q.pop();
		ans += s1 + s2;
		q.push(s1 + s2);
	}
	cout << ans << endl;
	return 0;
}
