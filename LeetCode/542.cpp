#include "all.h"

class Solution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		int n = matrix.size(), m = matrix[0].size();
		vector<vector<int>> ans = matrix;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				ans[i][j] = (ans[i][j] ? 0x3f3f3f3f : 0);
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < m; j++)
				ans[i][j] = min(ans[i][j], ans[i][j - 1] + 1);
			for (int j = m - 2; ~j; j--)
				ans[i][j] = min(ans[i][j], ans[i][j + 1] + 1);
		}
		for (int j = 0; j < m; j++) {
			for (int i = 1; i < n; i++)
				ans[i][j] = min(ans[i][j], ans[i - 1][j] + 1);
			for (int i = n - 2; ~i; i--)
				ans[i][j] = min(ans[i][j], ans[i + 1][j] + 1);
		}
		return ans;
	}
};

int main() {
	vector<vector<int>> matrix;
	int n, m;
	cin >> n >> m;
	matrix.resize(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int x; cin >> x;
			matrix[i].push_back(x);
		}
	vector<vector<int>> ans = Solution().updateMatrix(matrix);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << ans[i][j] << ' ';
		cout << endl;
	}
	return 0;
}
