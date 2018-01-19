#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};

char chess[5][5];
char word[10];
bool succ = 0, used[5][5];
int len;

void dfs(int x, int y, int k) {
	if (k == len) {
		succ = 1;
		return;
	}
	for (int i = 0; i < 8; i++)
		if (chess[x + dx[i]][y + dy[i]] == word[k])
			if (!used[x + dx[i]][y + dy[i]]) {
				used[x + dx[i]][y + dy[i]] = 1;
				dfs(x + dx[i], y + dy[i], k + 1);
				used[x + dx[i]][y + dy[i]] = 0;
			}
}

int main() {
	int T;
	cin >> T;
	for (int idx = 1; idx <= T; idx++) {
		for (int i = 1; i <= 3; i++) 
			for (int j = 1; j <= 3; j++)
				cin >> chess[i][j];
		int m;
		cin >> m;
		printf("Case #%d:\n", idx);
		for (int i = 0; i < m; i++) {
			succ = 0;
			scanf("%s", word);
			len = strlen(word);
			for (int i = 1; i <= 3; i++)
				for (int j = 1; j <= 3; j++)
					if (chess[i][j] == word[0]) {
						memset(used, 0, sizeof used);
						used[i][j] = 1;
						dfs(i, j, 1);
					}
			if (!succ || len <= 2)
				puts("0");
			else if (len <= 4)
				puts("1");
			else if (len == 5)
				puts("2");
			else if (len == 6)
				puts("3");
			else if (len == 7)
				puts("5");
			else if (len <= 9)
				puts("11");
		}
	}
	return 0;
}
