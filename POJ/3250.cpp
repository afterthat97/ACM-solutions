#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

int main() {
	int n;
	while (scanf("%d", &n) == 1) {
		stack<long long> s;
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			long long t; scanf("%lld", &t);
			while (!s.empty() && s.top() <= t) s.pop();
			sum += s.size();
			s.push(t);
		}
		printf("%lld\n", sum);
	}
	return 0;
}
