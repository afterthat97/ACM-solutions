#include <iostream>
#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n, m, k, a[10][10], ans;

bool valid(int x, int y) {
	if (x > 0 && y > 0 && x <= n && y <= m) return 1;
	return 0;
}

void dfs(int x, int y, int num, int sum) {
	for (int i = 0; i < 4; i++)
		for (int j = 1; j <= k; j++) {
			int nx = x + dx[i] * j;
			int ny = y + dy[i] * j;
			if (!valid(nx, ny) || a[nx][ny] <= num) continue;
			int tmp = a[nx][ny]; a[nx][ny] = 0;
			dfs(nx, ny, tmp, sum + tmp);
			a[nx][ny] = tmp;
		}
	if (sum > ans) ans = sum;
}

int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	int tmp = a[1][1]; a[1][1] = 0;
	dfs(1, 1, tmp, tmp);
	cout << ans << endl;
	return 0;
}
