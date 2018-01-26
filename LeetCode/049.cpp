#include "all.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<vector<int>, vector<string> > table;
        for (int i = 0; i < strs.size(); i++) {
            vector<int> seen(26);
            for (int j = 0; j < strs[i].size(); j++)
                ++seen[strs[i][j] - 'a'];
            table[seen].push_back(strs[i]);
        }
        for (map<vector<int>, vector<string> >::iterator it = table.begin();
            it != table.end(); it++)
            ans.push_back(it->second);
        return ans;
    }
};

int main() {
	int n; cin >> n;
	vector<string> strs(n);
	for (int i = 0; i < n; i++)
		cin >> strs[i];
	vector<vector<string>> ans = Solution().groupAnagrams(strs);
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j] << ' ' ;
		cout << endl;
	}
	return 0;
}
