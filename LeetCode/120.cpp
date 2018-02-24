#include "all.h"

class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
		int ans = INT_MAX;
		for (int i = 1; i < tri.size(); i++)
			for (int j = 0; j < tri[i].size(); j++)
				if (j > 0 && j < tri[i - 1].size())
					tri[i][j] += min(tri[i - 1][j], tri[i - 1][j - 1]);
				else if (j > 0)
					tri[i][j] += tri[i - 1][j - 1];
				else
					tri[i][j] += tri[i - 1][j];
		for (int i = 0; i < tri[tri.size() - 1].size(); i++)
			ans = min(tri[tri.size() - 1][i], ans);
		return ans;
    }
};

int main() {
	int n;
	
	while (cin >> n) {
		vector<vector<int>> tri;
		for (int i = 0; i < n; i++) {
			vector<int> cnt(i + 1);
			for (int j = 0; j <= i; j++)
				cin >> cnt[j];
			tri.push_back(cnt);
		}
		cout << Solution().minimumTotal(tri) << endl;
	}
	return 0;
}
