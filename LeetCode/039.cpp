#include "all.h"

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& a, int tar) {
        vector<vector<int>> ans;
		vector<int> cnt;
		solve(ans, cnt, a, tar, 0);
		return ans;
    }
	void solve(vector<vector<int>>& ans, vector<int>& cnt, vector<int>& a, int rest, int st) {
		if (rest < 0) return;
		if (rest == 0) ans.push_back(cnt);
		for (int i = st; i < a.size(); i++) {
			cnt.push_back(a[i]);
			solve(ans, cnt, a, rest - a[i], i);
			cnt.resize(cnt.size() - 1);
		}
	}
};

int main() {
	int n, tar; cin >> n >> tar;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	vector<vector<int>> ans = Solution().combinationSum(nums, tar);
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j] << ' ';
		cout << endl;
	}
	return 0;
}
