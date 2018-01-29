#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

char a[15], b[15];
int match[15] = {}, used[15] = {}, n, ans = 0x3f3f3f3f;

void dfs(int k) {
	if (k == n) {
		int tot = 0, tmp[15] = {}, inv[15] = {};
		for (int i = 0; i < n; i++) {
			tmp[i] = match[i]; inv[tmp[i]] = i;
			int x = a[i], y = b[tmp[i]];
			tot += min(abs(x - y), min(abs(10 + x - y), abs(-10 + x - y)));
		}
		for (int i = 0; i < n; i++)
			if (i != tmp[i]) {
				int j = inv[i];
				swap(inv[tmp[i]], inv[tmp[j]]);
				swap(tmp[i], tmp[j]);
				tot++;
			}
		ans = min(ans, tot);
	} else
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
