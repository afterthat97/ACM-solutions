#include "all.h"

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> cnt(n, 0), used1(n * 2, 0), used2(n * 2, 0), usedCol(n, 0);
        solve(ans, cnt, used1, used2, usedCol, n - 1);
        return ans;
    }
    void solve(vector<vector<string>>& ans, vector<int>& cnt, vector<int> used1,
               vector<int> used2, vector<int> usedCol, int k) {
        if (k == -1) {
            vector<string> tmp;
            for (int i = 0; i < cnt.size(); i++) {
                string str; str.resize(cnt.size());
                for (int j = 0; j < cnt.size(); j++)
                    str[j] = '.';
                str[cnt[i]] = 'Q';
                tmp.push_back(str);
            }
            ans.push_back(tmp);
        } else {
            for (int i = 0; i < cnt.size(); i++) {
                if (usedCol[i] || used1[i + k] || used2[cnt.size() + i - k])
                    continue;
                usedCol[i] = 1; used1[i + k] = 1; used2[cnt.size() + i - k] = 1;
                cnt[k] = i;
                solve(ans, cnt, used1, used2, usedCol, k - 1);
                usedCol[i] = 0; used1[i + k] = 0; used2[cnt.size() + i - k] = 0;
            }
        }
    }
};

int main() {
	int n; cin >> n;
	vector<vector<string>> ans = Solution().solveNQueens(n);
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j] << endl;
		cout << endl;
	}
	return 0;
}
