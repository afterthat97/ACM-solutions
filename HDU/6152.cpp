#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int T, n, g[15][15];

int main() {
	cin >> T;
	while (T--) {
		scanf("%d", &n);
		memset(g, 0, sizeof g);
		if (n > 5) {
			for (int i = 1; i < n; i++)
				for (int j = i + 1; j <= n; j++) {
					int t; scanf("%d", &t);
				}
			puts("Bad Team!");
		} else if (n < 3) {
			for (int i = 1; i < n; i++)
				for (int j = i + 1; j <= n; j++) {
					int t; scanf("%d", &t);
				}
			puts("Great Team!");
		} else {
			for (int i = 1; i < n; i++)
				for (int j = i + 1; j <= n; j++) {
					scanf("%d", &g[i][j]);
					g[j][i] = g[i][j];
				}
			int bad = 0;
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					for (int k = 1; k <= n; k++)
						if (i != j && i != k && j != k) {
							if (g[i][j] && g[i][k] && g[j][k])
								bad = 1;
							else if (g[i][j] == 0 && g[j][k] == 0 && g[i][k] == 0)
								bad = 1;
						}
			puts(bad ? "Bad Team!" : "Great Team!");
		}
	}
	return 0;
}
