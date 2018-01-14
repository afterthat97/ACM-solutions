#include <iostream>
#include <stdio.h>
using namespace std;

int n, a[10005], sum;

int main() {
	while (scanf("%d", &n) == 1) {
		sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		int avg = sum / n, ans = 0;
		for (int i = 0; i < n - 1; i++)
			if (a[i] != avg) {
				a[i + 1] += a[i] - avg;
				ans++;
			}
		cout << ans << endl;
	}
	return 0;
}
