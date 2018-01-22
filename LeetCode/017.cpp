#include "all.h"

class Solution {
public:
    vector<string> letterCombinations(string digits) {
		vector<string> res;
		if (digits == "") return res;
		string charmap[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
		res.push_back("");
		for (int i = 0; i < digits.size(); i++) {
			vector<string> tempres;
			string chars = charmap[digits[i] - '0'];
			for (int j = 0; j < res.size(); j++)
				for (int k = 0; k < chars.size(); k++)
					tempres.push_back(res[j] + chars[k]);
			res = tempres;
		}
		return res;
    }
};

int main() {
	string s; cin >> s;
	vector<string> ans = Solution().letterCombinations(s);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
	return 0;
}
