#include <iostream>
#include <stdio.h>
#include <stack>
#define maxn 100005
using namespace std;

int n, l[maxn], r[maxn], h[maxn];
stack<int> s;

int main() {
	while (scanf("%d", &n) == 1 && n) {
		s = stack<int>(); s.push(0);
		h[0] = -1; h[n + 1] = -1;
		for (int i = 1; i <= n; i++)
			scanf("%d", &h[i]);
		for (int i = 1; i <= n; i++) {
			while (h[s.top()] >= h[i]) s.pop();
			l[i] = s.top(); s.push(i);
		}
		s = stack<int>(); s.push(n + 1);
		for (int i = n; i >= 1; i--) {
			while (h[s.top()] >= h[i]) s.pop();
			r[i] = s.top(); s.push(i);
		}
		long long ans = 0;
		for (int i = 1; i <= n; i++)
			ans = max(ans, (long long) h[i] * (r[i] - l[i] - 1));
		printf("%lld\n", ans);
	}

	return 0;
}
