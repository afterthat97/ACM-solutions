#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int n, m, l[20], r[20];
int a[20][200], ans = 99999999;


void dfs(int cnt, int start, int tot) {
	if (cnt == n) {
		if (start == 0)
			ans = min(tot + n - 1 + r[cnt] - 1, ans);
		else
			ans = min(tot + n - 1 + m - l[cnt], ans);
		//if (ans == 9) cout << tot << ' ' << start << endl;
		return;
	}
	if (start == 0) {
		dfs(cnt + 1, 0, tot + (r[cnt] - 1) * 2);
		dfs(cnt + 1, 1, tot + m - 1);
	} else {
		dfs(cnt + 1, 0, tot + m - 1);
		dfs(cnt + 1, 1, tot + (m - l[cnt]) * 2);
	}
}

int main() {
	cin >> n >> m; m += 2;
	for (int i = 1; i <= n; i++) { r[i] = 1; l[i] = m; }
	for (int i = n; i >= 1; i--)
		for (int j = 1; j <= m; j++) {
			char ch; cin >> ch; a[i][j] = ch - '0';
			if (a[i][j] == 1) r[i] = j;
			if (a[i][j] == 1 && l[i] == m) l[i] = j;
		}
	int maxn = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i][j] == 1) maxn = i;
	n = maxn;
	if (n == 0) { cout << 0 << endl; return 0; }
	//for (int i = 1; i <= n; i++) cout << l[i] << ' ' << r[i] << endl;
	dfs(1, 0, 0);
	cout << ans << endl;
	return 0;
}
