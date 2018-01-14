#include <iostream>
#include <stdio.h>
using namespace std;

int n, now[1005], past[1005], epc[1005], t, idx;

int main() {
	while (scanf("%d", &n) == 1 && n > 0) {
		idx++;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &t);
			now[t] = i;
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &t);
			past[t] = i;
		}
		for (int i = 1; i <= n; i++) scanf("%d", &epc[i]);

		int sum = 0;
		for (int i = 1; i <= n; i++) {
			if (now[i] <= epc[i]) sum += 3;
			else if (now[i] <= past[i]) sum += 2;
			else sum += 1;
		}
		printf("Case %d: %d\n", idx, sum);
	}
	return 0;
}