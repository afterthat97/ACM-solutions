#include "all.h"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ans;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size();) {
			int l = i + 1, r = nums.size() - 1;
			while (l < r) {
				int sum = nums[l] + nums[r];
				if (sum < -nums[i])
					++l;
				else if (sum > -nums[i])
					--r;
				else { // sum == -nums[i]
					vector<int> cas { nums[i], nums[l], nums[r] };
					ans.push_back(cas);
					for (int b = nums[l]; b == nums[l]; l++);
					for (int b = nums[r]; b == nums[r]; r--);
				}
			}
			for (int b = nums[i]; b == nums[i]; i++);
		}
		return ans;
    }
};

int main() {
	int n; cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	vector<vector<int> > ans = Solution().threeSum(nums);
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j] << ' ';
		cout << endl;
	}
	return 0;
}
