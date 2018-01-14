#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int n, sum, maxl, stick[60];

int dfs(int cnt, int tot, int rest, int l) {
	stick[l]--; rest -= l;
	if (rest) {
		for (int next = min(rest, l); next; next--)
			if (stick[next] && dfs(cnt, tot, rest, next))
				return 1;
	} else {
		if (cnt == 1) return 1;
		int next = maxl;
		while (stick[next] == 0) --next;
		if (dfs(cnt - 1, tot, tot, next)) return 1;
	}
	stick[l]++;
	return 0;
}

int main() {
	while (scanf("%d", &n) == 1 && n) {
		memset(stick, 0, sizeof stick);
		sum = maxl = 0;
		for (int i = 0; i < n; i++) {
			int t; scanf("%d", &t);
			stick[t]++; sum += t; maxl = max(maxl, t);
		}
		for (int i = maxl; i <= sum; i++)
			if (sum % i == 0 && dfs(sum / i, i, i, maxl)) {
				printf("%d\n", i); break;
			}
	}
	return 0;
}
