#include "all.h"

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int len = 0;
		if (strs.size() == 0) return "";
		while (1) {
			for (int i = 0; i < strs.size(); i++) {
				if (strs[i].size() <= len)
					return strs[0].substr(0, len);
				if (strs[i][len] != strs[0][len])
					return strs[0].substr(0, len);
			}
			++len;
		}
	}
};

int main() {
	int n;
	vector<string> strs;
	cin >> n;
	strs.resize(n);
	for (int i = 0; i < n; i++)
		cin >> strs[i];
	cout << Solution().longestCommonPrefix(strs) << endl;
	return 0;
}
