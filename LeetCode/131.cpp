#include "all.h"

class Solution {
public:
    vector<vector<string>> partition(string a) {
        vector<vector<string>> ans;
		vector<string> cnt;
		solve(ans, cnt, a, 0);
		return ans;
    }
	void solve(vector<vector<string>>& ans, vector<string>& cnt, string& a, int st) {
		if (st == a.size()) ans.push_back(cnt);
		for (int i = st; i < a.size(); i++)
			if (isPalindrome(a.substr(st, i - st + 1))) {
				cnt.push_back(a.substr(st, i - st + 1));
				solve(ans, cnt, a, i + 1);
				cnt.resize(cnt.size() - 1);
			}
	}
	bool isPalindrome(string s) {
		int l = 0, r = s.size() - 1;
		while (l < r) {
			if (s[l] != s[r]) return false;
			l++; r--;
		}
		return true;
	}
};

int main() {
	string str; cin >> str;
	vector<vector<string>> ans = Solution().partition(str);
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j] << ' ';
		cout << endl;
	}
	return 0;
}
