#include "all.h"

class Solution {
public:
    vector<vector<int>> permute(vector<int>& a) {
		sort(a.begin(), a.end());
		vector<vector<int>> ans;
		do {
			ans.push_back(a);
		} while (get_next_permutation(&a[0], a.size()));
		return ans;
    }
	void rev(int* from, int* to) {
		while (from < to) {
			swap(*from, *to);
			from++; to--;
		}
	}
	bool get_next_permutation(int* a, int size) {
		int i = size - 2;
		while ((i >= 0) && (a[i] >= a[i + 1])) i--;
		if (i < 0) return 0;
		int j = size - 1;
		while (a[j] <= a[i]) j--;
		swap(a[j], a[i]);
		rev(a + i + 1, a + size - 1);
		return 1;
	}
};

int main() {
	int n; cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	vector<vector<int>> ans = Solution().permute(nums);
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j] << ' ';
		cout << endl;
	}
	return 0;
}
