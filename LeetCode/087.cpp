#include "all.h"

class Solution {
public:
    bool isScramble(string s1, string s2) {
		if (s1.size() != s2.size()) return false;
        if (s1.size() == 1) return s1[0] == s2[0];
		int l = s1.size(), cnt[26] = {};
		for (int i = 0; i < l; i++) {
			cnt[s1[i] - 'a']++;
			cnt[s2[i] - 'a']--;
		}
		for (int i = 0; i < 26; i++)
			if (cnt[i] != 0) return false;
		for (int m = 1; m < l; m++)
			if ((isScramble(s1.substr(0, m), s2.substr(0, m))
				&& isScramble(s1.substr(m, l), s2.substr(m, l)))
			|| (isScramble(s1.substr(0, m), s2.substr(l - m, m))
				&& isScramble(s1.substr(m, l), s2.substr(0, l - m))))
				return true;
		return false;
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
        
        bool ret = Solution().isScramble(s1, s2);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
