#include "all.h"

class Solution {
public:
    int minCut(string s) {
		if (s.size() == 0) return 0;
        vector<int> dp(s.size(), 0x3f3f3f3f);
		for (int i = 0; i < s.size(); i++) {
			for (int j = 0; i + j < s.size() && i - j >= 0; j++) {
				if (s[i + j] != s[i - j]) break;
				dp[i + j] = min(dp[i + j], i - j > 0 ? dp[i - j - 1] + 1 : 0);
			}
			for (int j = 0; i + j < s.size() && i - j >= 1; j++) {
				if (s[i + j] != s[i - j - 1]) break;
				dp[i + j] = min(dp[i + j], i - j > 1 ? dp[i - j - 2] + 1 : 0);
			}
		}
		return dp[s.size() - 1];
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

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        int ret = Solution().minCut(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
