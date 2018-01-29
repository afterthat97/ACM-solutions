#include "all.h"

class Solution {
public:
    bool isNumber(string s) {
		int i = 0;
		// skip the whilespaces
		for (; s[i] == ' '; i++);
		// check the significand
		if (s[i] == '+' || s[i] == '-') i++;
		int num = 0, dot = 0;
		for (; (s[i] <= '9' && s[i] >= '0') || s[i] == '.'; i++)
			s[i] == '.' ? ++dot : ++num;       
		if (dot > 1 || num < 1) return false;
		// check the exponent if exist
		if (s[i] == 'e') {
			i++;
			// check the significand
			if (s[i] == '+' || s[i] == '-') i++;
			int num = 0;
			for (; s[i] >= '0' && s[i] <= '9'; i++) ++num;
			if (num < 1) return false;
		}
		// skip the trailing whitespaces
		for (; s[i] == ' '; i++);
		return s[i] == 0;
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
        
        bool ret = Solution().isNumber(s);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
