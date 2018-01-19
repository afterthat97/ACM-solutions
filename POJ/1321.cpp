#include <iostream>
#include <cstring>
using namespace std;

int n, k, num, ans;
int dat[10][10];
int used[20];

void dfs(int x) {//x��ʾ��
	if (num == k) {
		ans++;
		return;
	}
	if (x > n) return;
	for (int i = 1; i <= n; i++)
		if (dat[i][x] && !used[i]) {//[i, x]
			used[i] = 1;//��i���ѷ�����
			num++;
			dfs(x + 1);//������һ��
			num--;
			used[i] = 0;
		}
	dfs(x + 1);//�������ӣ�ֱ�ӵݹ���һ��
}

int main() {
	while (scanf("%d %d", &n, &k) == 2 && n != -1) {
		memset(dat, 0, sizeof(dat));
		memset(used, 0, sizeof(used));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				char ch;
				cin >> ch;
				if (ch == '#')dat[i + 1][j + 1] = 1;
			}
		num = ans = 0;
		dfs(1);
		cout << ans << endl;
	}
	return 0;
}