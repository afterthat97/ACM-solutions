#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

stack<int> s;
int n, a[1005], ans;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	s.push(0);
	for (int i = 1; i <= n + 1; i++) {
		if (a[s.top()] <= a[i])  s.push(i);
		else {
			while (a[s.top()] > a[i]) {
				int idx = s.top(); s.pop();
				if ((i - s.top() - 1) * a[idx] > ans) {
					ans = (i - s.top() - 1) * a[idx];
				}
			}
			s.push(i);
		}
	}
	cout << ans << endl;
	return 0;
}
