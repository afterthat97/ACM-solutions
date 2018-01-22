#include "all.h"

class Solution {
public:
    int longestValidParentheses(string a) {
		stack<int> s; s.push(-1);
		int ans = 0;
		if (a.size() == 0) return ans;
		for (int i = 0; i < a.size(); i++)
			if (a[i] == '(')
				s.push(i);
			else {
				s.pop();
				if (s.empty())
					s.push(i);
				else
					ans = max(ans, i - s.top());
			}
		return ans;
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
        
        int ret = Solution().longestValidParentheses(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
