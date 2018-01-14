#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
using namespace std;

int n, ans, dat[27][27], flag[27];//flag[i]:i��Ƶ��
bool used[27];

void dfs(int x) {
	memset(used, 0, sizeof(used));
	for (int i = 1; i <= n; i++)
		if (dat[x][i] && flag[i])
			used[flag[i]] = 1;//��x���ڵĵ�̨��Ƶ�ʣ����ܺ������ظ�
	for (int i = 1; i <= n; i++)//��С��Ƶ�ʿ�ʼ��
		if (!used[i]) {//��Χû��̨�ù�iƵ��
			flag[x] = i;
			if (i > ans) ans = i;
			break;
		}
	for (int i = 1; i <= n; i++)
		if (dat[x][i] && !flag[i])
			dfs(i);//������һ����û����Ƶ�ʵĵ�̨
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
			if (!flag[i])//�����̨i��û�б�����Ƶ��
				dfs(i);
		if (ans == 1) cout << "1 channel needed.\n";
		else cout << ans << " channels needed.\n";
	}
	return 0;
}