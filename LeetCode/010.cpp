#include "all.h"

int dp[1005][1005];

class Solution {
public:
    bool isMatch(string s, string p) {
		memset(dp, 0, sizeof dp);
		dp[0][0] = 1;
		for (int i = 0; i <= s.size(); i++)
			for (int j = 1; j <= p.size(); j++) {
				if (p[j - 1] == '*') {
					bool match = i && (s[i - 1] == p[j - 2] || p[j - 2] == '.');
					dp[i][j] = dp[i][j - 2] || (match && dp[i - 1][j]);
				} else {
					bool match = i && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
					dp[i][j] = match && dp[i - 1][j - 1];
				}
			}
		return dp[s.size()][p.size()];
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
