#include "all.h"

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { 1, 0, -1, 0 };

class Solution {
public:
    bool exist(vector<vector<char>>& a, string word) {
        if (a.size() == 0 || a[0].size() == 0) return false;
		for (int i = 0; i < a.size(); i++)
			for (int j = 0; j < a[0].size(); j++)
				if (solve(a, word, i, j, 0)) return true;
		return false;
    }
	bool solve(vector<vector<char>>& a, string& word, int x, int y, int k) {
		if (k == word.size()) return true;
		if (x < 0 || y < 0 || x >= a.size() || y >= a[0].size())
			return false;
		if (a[x][y] != word[k]) return false;
		char tmp = a[x][y];
		a[x][y] = 0;
		for (int i = 0; i < 4; i++)
			if (solve(a, word, x + dx[i], y + dy[i], k + 1))
				return true;
		a[x][y] = tmp;
		return false;
	}
};

int main() {
	int n, m; cin >> n >> m;
	vector<vector<char>> a(n, vector<char>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	string word;
	cin >> word;
	cout << Solution().exist(a, word) << endl;
	return 0;
}
