#include "all.h"

class Solution {
private:
    vector<vector<string>> ans;
public:
    int diff(string str1, string str2) {
        int ans = 0;
        for (int i = 0; i < str1.size(); i++)
            if (str1[i] != str2[i]) ans++;
        return ans;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<string> cnt;
        vector<bool> vis(wordList.size(), false);
        ans.clear();
        bool pass = false;
        for (int i = 0; i < wordList.size(); i++)
            if (wordList[i] == endWord)
                pass = true;
        if (!pass) return ans;
        cnt.push_back(beginWord);
        dfs(cnt, endWord, wordList, vis);
        return ans;
    }
    void dfs(vector<string>& cnt, const string& endWord, vector<string>& wordList, vector<bool>& vis) {
        if (cnt.back() == endWord) {
            if (ans.size() == 0 || cnt.size() == ans[0].size()) {
                ans.push_back(cnt);
            } else if (cnt.size() < ans[0].size()) {
                ans.clear();
                ans.push_back(cnt);
            }
            return;
        }
        if (ans.size() && cnt.size() >= ans[0].size()) return;
        for (int i = 0; i < wordList.size(); i++)
            if (!vis[i] && diff(cnt.back(), wordList[i]) == 1) {
                vis[i] = true;
                cnt.push_back(wordList[i]);
                dfs(cnt, endWord, wordList, vis);
                cnt.pop_back();
                vis[i] = false;
            }
    }
};

int main() {
    int n;
    while (cin >> n) {
        string beginWord, endWord;
        vector<string> wordList;
        for (int i = 0; i < n; i++) {
            string str; cin >> str;
            wordList.push_back(str);
        }
        cin >> beginWord >> endWord;
        vector<vector<string>> ans = Solution().findLadders(beginWord, endWord, wordList);
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++)
                cout << ans[i][j] << ' ';
            cout << endl;
        }
    }
    return 0;
}
