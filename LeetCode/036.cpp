#include "all.h"

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
		for (int i = 0; i < 9; i++) {
			bool seen[9] = {};
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == '.') continue;
				if (seen[board[i][j] - '1']) return false;
				seen[board[i][j] - '1'] = true;
			}
		}
		for (int j = 0; j < 9; j++) {
			bool seen[9] = {};
			for (int i = 0; i < 9; i++) {
				if (board[i][j] == '.') continue;
				if (seen[board[i][j] - '1']) return false;
				seen[board[i][j] - '1'] = true;
			}
		}
        for (int i = 0; i < 9; i += 3)
			for (int j = 0; j < 9; j += 3) {
				bool seen[9] = {};
				for (int dx = 0; dx < 3; dx++)
					for (int dy = 0; dy < 3; dy++) {
						int nx = i + dx, ny = j + dy;
						if (board[nx][ny] == '.') continue;
						if (seen[board[nx][ny] - '1']) return false;
						seen[board[nx][ny] - '1'] = true;
					}
			}
		return true;
    }
};

int main() {
	vector<vector<char>> board(9);
	for (int i = 0; i < 9; i++) {
		board[i].resize(9);
		for (int j = 0; j < 9; j++)
			cin >> board[i][j];
	}
	cout << Solution().isValidSudoku(board);
}
