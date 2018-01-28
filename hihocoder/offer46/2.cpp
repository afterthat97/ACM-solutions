#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

char a[15], b[15];
int match[15] = {}, used[15] = {}, n, ans = 0x3f3f3f3f;

void dfs(int k) {
	if (k == n) {
		int tot = 0, tmp[15] = {};
		for (int i = 0; i < n; i++) tmp[i] = match[i];
		for (int i = 0; i < n; i++) {
			int x = a[i], y = b[match[i]];
			tot += min(abs(x - y), min(abs(10 + x - y), abs(-10 + x - y)));
			if (i != tmp[i]) {
				for (int j = i + 1; j < n; j++)
					if (tmp[j] == i) {
						swap(tmp[j], tmp[i]);
						break;
					}
				tot++;
			}
		}
		ans = min(ans, tot);
		return;
	}
	for (int i = 0; i < n; i++)
		if (!used[i]) {
			used[i] = 1;
			match[k] = i;
			dfs(k + 1);
			used[i] = 0;
		}
}

int main() {
	while (cin >> n >> a >> b) {
		ans = 0x3f3f3f3f;
		memset(used, 0, sizeof used);
		dfs(0);
		cout << ans << endl;
	}
	return 0;
}
