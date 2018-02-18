#include "all.h"

class Solution {
public:
    int numDecodings(string s) {
		if (s.size() == 0) return 0;
        vector<int> dp(s.size(), 0);
		dp[0] = s[0] == '0' ? 0 : 1;
		for (int i = 1; i < dp.size(); i++) {
			if (s[i] != '0') dp[i] += dp[i - 1];
			if (s[i - 1] == '1')
				dp[i] += i > 1 ? dp[i - 2] : 1;
			else if (s[i - 1] == '2' && s[i] <= '6')
				dp[i] += i > 1 ? dp[i - 2] : 1;
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
        
        int ret = Solution().numDecodings(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
