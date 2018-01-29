#include "all.h"

class Solution {
public:
    int minPathSum(vector<vector<int>>& a) {
        if (a.size() == 0 || a[0].size() == 0) return 0;
		int n = a.size(), m = a[0].size();
		vector<vector<int>> dp(n);
		for (int i = 0; i < n; i++) dp[i].resize(m);
		dp[0][0] = a[0][0];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				dp[i][j] = (i + j == 0 ? 0 : 0x7f7f7f7f);
				if (i - 1 >= 0) dp[i][j] = min(dp[i][j], dp[i - 1][j]);
				if (j - 1 >= 0) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
				dp[i][j] += a[i][j];
			}
		return dp[n - 1][m - 1];
    }
};

int main() {
	int n, m; cin >> n >> m;
	vector<vector<int>> a(n);
	for (int i = 0; i < n; i++) {
		a[i].resize(m);
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	}
	cout << Solution().minPathSum(a) << endl;
	return 0;
}
