#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int n, m, w[1005], b[1005], pos[1005], ans;

int main() {
	memset(pos, -1, sizeof pos);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &w[i]);
	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
		if (pos[b[i]] == -1) {
			for (int j = 0; j < i; j++)
				if (pos[b[j]] == j)
					ans += w[b[j]];
			pos[b[i]] = i;
		} else {
			for (int j = pos[b[i]] + 1; j < i; j++)
				if (pos[b[j]] == j)
					ans += w[b[j]];
			pos[b[i]] = i;
		}
	}
	cout << ans << endl;
	return 0;
}
