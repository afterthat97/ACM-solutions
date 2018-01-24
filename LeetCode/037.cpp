#include "all.h"

class Solution {
public:
	const int belong[10] = { 0, 1, 1, 1, 4, 4, 4, 7, 7, 7 };
	int map[10][10], used[10][10][10];
    void solveSudoku(vector<vector<char>>& board) {
		int blank = 0;
		memset(map, 0, sizeof map);
		memset(used, 0, sizeof used);
		for (int i = 1; i <= 9; i++)
			for (int j = 1; j <= 9; j++) {
				char ch = board[i - 1][j - 1];
				if (ch == '.')
					blank++;
				else
					fill(i, j, ch - '0');
			}
		if (dfs(blank) == 0) return;
		for (int i = 1; i <= 9; i++)
			for (int j = 1; j <= 9; j++)
				board[i - 1][j - 1] = map[i][j] + '0';
    }
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
				if (map[i][j] == 0 && used[i][j][0] >= maxx) {
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
};

int main() {
	while (1) {
		vector<vector<char>> a(9);
		for (int i = 0; i < 9; i++) {
			a[i].resize(9);
			for (int j = 0; j < 9; j++)
				cin >> a[i][j];
		}
		Solution().solveSudoku(a);
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout << a[i][j] << ' ';
			cout << endl;
		}
	}
	return 0;
}
