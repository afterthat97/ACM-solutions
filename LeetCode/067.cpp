#include "all.h"

class Solution {
public:
    string addBinary(string a, string b) {
        string ans; ans.resize(max(a.size(), b.size()) + 1);
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		for (int i = 0, c = 0; i < ans.size(); i++) {
			ans[i] += c;
			if (i < a.size()) ans[i] += a[i] - '0';
			if (i < b.size()) ans[i] += b[i] - '0';
			c = ans[i] / 2; ans[i] = ans[i] % 2; ans[i] += '0';
		};
		while (ans.size() > 1 && ans.back() == '0')
			ans.erase(ans.size() - 1, 1);
		reverse(ans.begin(), ans.end());
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
        string a = stringToString(line);
        getline(cin, line);
        string b = stringToString(line);
        
        string ret = Solution().addBinary(a, b);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
