#include "all.h"

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> ans;
		unordered_map<string, int> tot, cnt;
		if (words.size() == 0) return ans;
		int n = words.size(), len = words[0].size();
		for (int i = 0; i < words.size(); i++)
			++tot[words[i]];
		for (int i = 0; i < words[0].size(); i++) {
			if (i + n * len > s.size()) break;
			cnt.clear();
			for (int j = i, left = i, num = 0;; j += len) {
				string sub = s.substr(j, len);
				if (sub.size() < len) break;
				if (tot[sub]) {
					++cnt[sub]; ++num;
					while (cnt[sub] > tot[sub]) {
						--cnt[s.substr(left, len)]; --num;
						left += len;
					}
				} else {
					cnt.clear(); num = 0;
					left = j + len;
				}
				if (num == n) {
					ans.push_back(left);
					--cnt[s.substr(left, len)]; --num;
					left += len;
				}
			}
		}
		return ans;
	}
};

int main() {
	int n; cin >> n;
	vector<string> words(n);
	for (int i = 0; i < n; i++)
		cin >> words[i];
	string s; cin >> s;
	vector<int> idx = Solution().findSubstring(s, words);
	for (int i = 0; i < idx.size(); i++)
		cout << idx[i] << endl;
	return 0;
}
