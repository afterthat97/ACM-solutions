#include "all.h"

char* manacher(const char* str) {
	int slen = strlen(str), tlen = slen * 2 + 3;
	char* t = new char[tlen];
	int* p = new int[tlen];
	t[0] = '^'; // head
	t[tlen - 2] = '#'; // tail
	t[tlen - 1] = '$'; // tail
	if (slen == 0) return 0;
	for (int i = 0; i < slen; i++) {
		t[i * 2 + 1] = '#';
		t[i * 2 + 2] = str[i];
	}
	int c = 0, r = 0;
	for (int i = 1; i < tlen - 1; i++) {
		p[i] = (r > i) ? min(r - i, p[2 * c - i]) : 0;
		while (t[i + p[i] + 1] == t[i - p[i] - 1]) ++p[i];
		if (i + p[i] > r) {
			c = i;
			r = i + p[i];
		}
	}
	int maxl = 0, center = 0;
	for (int i = 1; i < tlen - 1; i++)
		if (p[i] > maxl) {
			maxl = p[i];
			center = i;
		}
	char* ans = new char[maxl + 1];
	for (int i = 0; i < maxl; i++)
		ans[i] = str[i + (center - maxl - 1) / 2];
	ans[maxl] = 0;
	delete[] t; delete[] p;
	return ans;
}

class Solution {
public:
    string longestPalindrome(string s) {
        return manacher(s.c_str());
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
        
        string ret = Solution().longestPalindrome(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
