#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int belong[10] = { 0, 1, 1, 1, 4, 4, 4, 7, 7, 7 };
int map[10][10];
int used[10][10][10];

inline void fill(int x, int y, int v) {
	map[x][y] = v;
	for (int m = 1; m <= 9; m++) {
		if (used[x][m][v] == 0) ++used[x][m][0];
		if (used[m][y][v] == 0 && m != x) ++used[m][y][0];
		++used[x][m][v];
		if (m != x) ++used[m][y][v];
	}
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			int px = belong[x] + i, py = belong[y] + j;
			if (used[px][py][v] == 0)
				++used[px][py][0];
			++used[px][py][v];
		}
}

inline void defill(int x, int y, int v) {
	map[x][y] = 0;
	for (int m = 1; m <= 9; m++) {
		if (used[x][m][v] == 1) --used[x][m][0];
		if (used[m][y][v] == 1 && m != x) --used[m][y][0];
		--used[x][m][v];
		if (m != x) --used[m][y][v];
	}
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			int px = belong[x] + i, py = belong[y] + j;
			if (used[px][py][v] == 1)
				--used[px][py][0];
			--used[px][py][v];
		}
}

int dfs(int blank) {
	if (blank == 0) return 1;
	int px = 0, py, maxx = 0;
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
			if (map[i][j] == 0 && used[i][j][0] > maxx) {
				maxx = used[i][j][0];
				px = i; py = j;
			}
	if (maxx == 9) return 0;
	for (int k = 1; k <= 9; k++)
		if (!used[px][py][k]) {
			fill(px, py, k);
			if (dfs(blank - 1)) return 1;
			defill(px, py, k);
		}
	return 0;
}

int main() {
	int T; cin >> T;
	for (int idx = 1; idx <= T; idx++) {
		int blank = 0;
		memset(map, 0, sizeof map);
		memset(used, 0, sizeof used);
		for (int i = 1; i <= 9; i++)
			for (int j = 1; j <= 9; j++) {
				char ch; cin >> ch;
				if (ch == '0')
					blank++;
				else
					fill(i, j, ch - '0');
			}
		if (dfs(blank) == 0) return 0;
		printf("Scenario #%d:\n", idx);
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++)
				putchar(map[i][j] + '0');
			putchar('\n');
		}
		putchar('\n');
	}
	return 0;
}
