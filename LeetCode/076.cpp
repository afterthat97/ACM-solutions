#include "all.h"

class Solution {
public:
    string minWindow(string s, string t) {
        int tot[130] = {};
		for (int i = 0; i < t.size(); i++) tot[t[i]]++;
		int l = 0, r = 0, cnt = t.size();
		string ans; int len = 0x3f3f3f3f;
		while (r < s.size()) {
			if (tot[s[r]] > 0) cnt--;
			tot[s[r]]--;
			while (cnt == 0 && tot[s[l]] <= 0) {
				if (s.substr(l, r - l + 1).size() < len) {
					ans = s.substr(l, r - l + 1);
					len = ans.size();
				}
				tot[s[l]]++;
				if (tot[s[l]] > 0) cnt++;
				l++;
			}
			r++;
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
        getline(cin, line);
        string t = stringToString(line);
        
        string ret = Solution().minWindow(s, t);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
