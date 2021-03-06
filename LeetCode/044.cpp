#include "all.h"

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        if (n + m == 0) return true;
        vector<vector<int>> dp(n + 1);
        for (int i = 0; i <= n; i++)
            dp[i].resize(m + 1);
        dp[0][0] = 1;
        for (int i = 0; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if ((p[j - 1] == '?' && i) || p[j - 1] == s[i - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*')
                    dp[i][j] = (i ? dp[i - 1][j] : 0) || dp[i][j - 1];
        return dp[n][m];
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        string p = stringToString(line);
        
        bool ret = Solution().isMatch(s, p);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
