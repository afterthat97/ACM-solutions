#include "all.h"

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
		vector<int> cnt;
		solve(ans, cnt, n, k, 1);
		return ans;
    }
	void solve(vector<vector<int>>& ans, vector<int>& cnt, int n, int k, int st) {
		if (k == 0)
			ans.push_back(cnt);
		else
			for (int i = st; i <= n; i++) {
				cnt.push_back(i);
				solve(ans, cnt, n, k - 1, i + 1);
				cnt.pop_back();
			}
	}
};

int main() {
	int n, k;
	while (cin >> n >> k) {
		vector<vector<int>> ans = Solution().combine(n, k);
		for (int i = 0; i < ans.size(); i++) {
			cout << '[' << ans[i][0];
			for (int j = 1; j < ans[i].size(); j++)
				cout << ',' << ans[i][j];
			cout << ']' << endl;
		}
	}
	return 0;
}
