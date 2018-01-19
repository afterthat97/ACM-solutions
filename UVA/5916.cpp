#include <stdio.h>

int a[10005], p[5005], n, j;

int tile() {
	int ans = 0, pos = j - 1;
	for (; p[pos] > n; pos--);
	int s = 0;
	for (; pos - s >= 0; pos--) {
		int now = p[pos];
		for (; now * p[s] <= n; s++)
			now = now * p[s];
		ans++;
	}
	return ans;
}

int main() {
	for (int i = 0; i < 10005; i++)
		a[i] = 1;
	for (int i = 2; i < 10005; i++)
		if (a[i]) {
			for (int j = 2; i * j < 10005; j++)
				a[i * j] = 0;
		}
	for (int i = 2; i < 10005; i++)
		if (a[i])
			p[j++] = i;

	while (scanf("%d", &n) == 1) {
		printf("%d\n", tile());
	}
	return 0;
}