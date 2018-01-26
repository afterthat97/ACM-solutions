#include "all.h"

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { 1, 0, -1, 0 };

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
		vector<int> ans;
		if (a.size() == 0 || a[0].size() == 0) return ans;
        int dir = 0, m = a.size(), n = a[0].size(), left = m * n - 1;
		vector<vector<bool>> vis(m);
		for (int i = 0; i < m; i++) vis[i].resize(n);
		ans.push_back(a[0][0]);
		vis[0][0] = 1;
		for (int x = 0, y = 0; left;) {
			int nx = x + dx[dir], ny = y + dy[dir];
			if (nx >= m || ny >= n || nx < 0 || ny < 0 || vis[nx][ny])
				dir = (dir + 1) % 4;
			else {
				ans.push_back(a[nx][ny]);
				vis[nx][ny] = 1;
				x = nx; y = ny; --left;
			}
		}
		return ans;
    }
};

int main() {
	int m, n; cin >> m >> n;
	vector<vector<int>> mat(m);
	for (int i = 0; i < m; i++) {
		mat[i].resize(n);
		for (int j = 0; j < n; j++)
			cin >> mat[i][j];
	}
	vector<int> ans = Solution().spiralOrder(mat);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}
