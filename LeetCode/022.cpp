#include "all.h"

void dfs(int l, int r, string str, vector<string>& ans) {
	if (l == 0 && r == 0) {
		ans.push_back(str); return;
	}
	if (l) dfs(l - 1, r + 1, str + '(', ans);
	if (r) dfs(l, r - 1, str + ')', ans);
}

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
		dfs(n, 0, "", ans);
		return ans;
    }
};

int main() {
	int n;
	while (cin >> n) {
		vector<string> ans = Solution().generateParenthesis(n);
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << endl;
	}
	return 0;
}
