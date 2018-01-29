#include "all.h"

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
		if (a.size() == 0 || a[0].size() == 0) return 0;
        int n = a.size(), m = a[0].size();
		vector<vector<int>> dp(n);
		for (int i = 0; i < n; i++) dp[i].resize(m);
		dp[0][0] = 1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 1) { dp[i][j] = 0; continue; }
				if (j - 1 >= 0) dp[i][j] += dp[i][j - 1];
				if (i - 1 >= 0) dp[i][j] += dp[i - 1][j];
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
	cout << Solution().uniquePathsWithObstacles(a) << endl;
	return 0;
}
