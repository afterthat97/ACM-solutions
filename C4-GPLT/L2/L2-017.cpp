#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int a[100005], ans1, ans2, n1, n2;

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) 
		scanf("%d", &a[i]);
	sort(a, a + n);
	if (n & 1) {
		n1 = n2 = n / 2;
		for (int i = 0; i < n / 2; i++)
			ans1 += a[i];
		for (int i = (n / 2) + 1; i < n; i++)
			ans2 += a[i];
		if (ans1 > ans2) {
			ans1 += a[n / 2];
			n1++;
		} else {
			ans2 += a[n / 2];
			n2++;
		}
	} else {
		n1 = n2 = n / 2;
		for (int i = 0; i < n / 2; i++)
			ans1 += a[i];
		for (int i = n / 2; i < n; i++)
			ans2 += a[i];
	}
	printf("Outgoing #: %d\n", n2);
	printf("Introverted #: %d\n", n1);
	printf("Diff = %d", ans2 - ans1);
	return 0;
}
