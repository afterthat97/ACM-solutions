#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define maxm 2000005
#define maxn 200005
int a[maxn], b[maxm], n, ans, diff[maxm];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
		scanf("%d", &a[i]);
	std::sort(a, a + n);
	int cnt = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] != a[cnt]) { a[++cnt] = a[i]; } 
	}
	n = cnt + 1; a[n] = maxm - 1; 
	for (int i = 0; i < n; i++)
		for (int j = a[i] + 1; j <= a[i + 1]; j++) {
			b[j] = a[i];
			diff[j] = a[i + 1] + 1;
		}
	for (int i = 0; i < n; i++)
		if (a[i] != 1)
			for (int j = a[i] << 1; j < maxm; j += max((diff[j] - j) / a[i], 1) * a[i])
				ans = std::max(ans, b[j] % a[i]);
	printf("%d\n", ans);
	return 0;
}
