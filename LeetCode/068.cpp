#include "all.h"

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxl) {
		vector<string> ans;
		for (int i = 0, j; i < words.size(); i = j) {
			string cnt = words[i];
			int l = words[i].size();
			for (j = i + 1; j < words.size(); j++) {
				if (l + words[j].size() + j - i > maxl) break;
				l += words[j].size();
			}
			int blanks = maxl - l;
			for (int k = 0; k < j - i - 1; k++) {
				if (j == words.size())
					cnt = cnt + ' ';
				else {
					cnt = cnt + string(blanks / (j - i - 1), ' ');
					if (k < blanks % (j - i - 1)) cnt = cnt + ' ';
				}
				cnt = cnt + words[i + k + 1];
			}
			cnt += string(maxl - cnt.size(), ' ');
			ans.push_back(cnt);
		}
		return ans;
    }
};

int main() {
	int n, l; cin >> n >> l;
	vector<string> words(n);
	for (int i = 0; i < n; i++)
		cin >> words[i];
	vector<string> ans = Solution().fullJustify(words, l);
	for (int i = 0; i < ans.size(); i++)
		cout << "\"" << ans[i] << "\"\n";
	return 0;
}
