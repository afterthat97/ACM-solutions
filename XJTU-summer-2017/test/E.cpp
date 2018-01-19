#include <iostream>
#include <stdio.h>
#include <stack>
#include <cstring>
using namespace std;

stack<int> s;
int n;
long long a[5005];

int main() {
	while (scanf("%d", &n) == 1) {
		memset(a, 0, sizeof a);
		for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
		while (!s.empty()) s.pop(); s.push(0);
		long long ans = 0;
		for (int i = 1; i <= n + 1; i++)
			if (a[s.top()] <= a[i])
				s.push(i);
			else {
				while (a[s.top()] > a[i]) {
					int idx = s.top(); s.pop();
					if ((i - s.top() - 1) * a[idx] > ans)
						ans = (i - s.top() - 1) * a[idx];
				}
				s.push(i);
			}
		printf("%lld\n", ans);
	}
	return 0;
}
