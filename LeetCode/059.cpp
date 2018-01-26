#include "all.h"

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { 1, 0, -1, 0 };

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> ans(n);
		if (n == 0) return ans;
		for (int i = 0; i < n; i++) ans[i].resize(n);
        int dir = 0, left = n * n - 1;
		ans[0][0] = n * n - left;
		for (int x = 0, y = 0; left;) {
			int nx = x + dx[dir], ny = y + dy[dir];
			if (nx >= n || ny >= n || nx < 0 || ny < 0 || ans[nx][ny])
				dir = (dir + 1) % 4;
			else {
				x = nx; y = ny; --left;
				ans[nx][ny] = n * n - left;
			}
		}
		return ans;
    }
};

int main() {
	int n; cin >> n;
	vector<vector<int>> ans = Solution().generateMatrix(n);
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j] << ' ';
		cout << endl;
	}
	return 0;
}
