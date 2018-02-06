#include "all.h"

class Solution {
public:
    vector<string> restoreIpAddresses(string str) {
		vector<string> ans, cnt;
		solve(ans, cnt, str);
		return ans;
    }
	void solve(vector<string>& ans, vector<string>& cnt, string str) {
		if (cnt.size() == 4) {
			if (str.size() != 0) return;
			string tmp = cnt[0];
			for (int i = 1; i < 4; i++)
				tmp += ("." + cnt[i]);
			ans.push_back(tmp);
		} else
			for (int i = 1; i <= min((int)str.size(), 3); i++) {
				string tmp = str.substr(0, i);
				if (tmp[0] == '0' && tmp.size() > 1) continue;
				int val = atoi(tmp.c_str());
				if (val >= 0 && val < 256) {
					cnt.push_back(tmp);
					solve(ans, cnt, str.substr(i));
					cnt.pop_back();
				}
			}
	}
};

int main() {
	string str;
	while (cin >> str) {
		vector<string> ans = Solution().restoreIpAddresses(str);
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << endl;
	}
	return 0;
}
