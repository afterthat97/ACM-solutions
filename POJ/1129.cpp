#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
using namespace std;

int n, ans, dat[27][27], flag[27];//flag[i]:i的频率
bool used[27];

void dfs(int x) {
	memset(used, 0, sizeof(used));
	for (int i = 1; i <= n; i++)
		if (dat[x][i] && flag[i])
			used[flag[i]] = 1;//和x相邻的电台的频率，不能和他们重复
	for (int i = 1; i <= n; i++)//从小的频率开始试
		if (!used[i]) {//周围没电台用过i频率
			flag[x] = i;
			if (i > ans) ans = i;
			break;
		}
	for (int i = 1; i <= n; i++)
		if (dat[x][i] && !flag[i])
			dfs(i);//考虑下一个还没分配频率的电台
}

int main() {
	while (scanf("%d", &n) && n) {
		memset(dat, 0, sizeof(dat));
		memset(flag, 0, sizeof(flag));
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int i = 2; i < s.size(); i++) {
				dat[s[0] - 'A' + 1][s[i] - 'A' + 1] = 1;
				dat[s[i] - 'A' + 1][s[0] - 'A' + 1] = 1;
			}
		}

		ans = 0;
		for (int i = 1; i <= n; i++)
			if (!flag[i])//如果电台i还没有被分配频率
				dfs(i);
		if (ans == 1) cout << "1 channel needed.\n";
		else cout << ans << " channels needed.\n";
	}
	return 0;
}