#include "all.h"

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
		int n = s1.size(), m = s2.size();
		if (n + m != s3.size()) return false;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
		dp[0][0] = true;
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= m; j++) {
				if (i && s3[i + j - 1] == s1[i - 1])
					dp[i][j] |= dp[i - 1][j];
				if (j && s3[i + j - 1] == s2[j - 1])
					dp[i][j] |= dp[i][j - 1];
			}
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
        string s1 = stringToString(line);
        getline(cin, line);
        string s2 = stringToString(line);
        getline(cin, line);
        string s3 = stringToString(line);
        
        bool ret = Solution().isInterleave(s1, s2, s3);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
