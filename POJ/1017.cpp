#include <iostream>
#include <stdio.h>
using namespace std;

int a[7];

int main() {
	while (1) {
		int sum = 0;
		for (int i = 1; i <= 6; i++) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		if (!sum) break;
		int ans = a[6] + a[5] + a[4] + (a[3] + 3) / 4;
		int rest3 = (4 - a[3] % 4) % 4;
		if (rest3 == 1) { a[1] -= 5; a[2]--; }
		else if (rest3 == 2) {  a[1] -= 6; a[2] -= 3; }
		else if (rest3 == 3) {  a[1] -= 7; a[2] -= 5; }
		a[1] -= a[5] * 11;
		a[2] -= a[4] * 5;
		if (a[2] > 0) {
			ans += (a[2] + 8) / 9;
			int rest2 = (9 - a[2] % 9) % 9;
			a[1] -= rest2 * 2 * 2;
		} else if (a[2] < 0)
			a[1] -= -a[2] * 2 * 2;
		if (a[1] > 0)
			ans += (a[1] + 35) / 36;
		printf("%d\n", ans);
	}

	return 0;
}
