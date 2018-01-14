#include <iostream>
#include <stdio.h>
#define maxn 1005
using namespace std;

int a[maxn], n, r;

void work(int x) {
	for (int i = 0; i <= r; i++) {
		if (x - i >= 0) a[x - i] = 0;
		if (x + i < maxn) a[x + i] = 0;
	}
}

int main() {
	while (scanf("%d %d", &r, &n) == 2 && r != -1) {
		for (int i = 0; i < n; i++) {
			int t; scanf("%d", &t); a[t] = 1;
		}
		int ans = 0;
		for (int i = 0; i < maxn; i++)
			if (a[i]) {
				ans++;
				for (int j = min(i + r, maxn - 1); j >= i; j--)
					if (a[j]) work(j);
			}
		cout << ans << endl;
	}
	return 0;
}
