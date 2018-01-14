#include <stdio.h>

int n, m;
char ch;

int main() {
	while (scanf("%d%d", &n, &m) == 2) {
		int ans = 1, mod = 0;
		bool have = 0;
		for (int i = 0; i < n; i++) {
			ch = getchar();
			while (ch > '9' || ch < '0') ch = getchar();
			mod = (mod * 10 + ch - 48) % m;
			if (mod == 0 && i < n - 1) {
				ans = (ans * 2) % (1000000007);
				have = 1;
			}
		}
		if (!have || mod != 0)  printf("0\n");
		else printf("%d\n", ans);
	}
	return 0;
}