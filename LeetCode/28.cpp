#include "all.h"

#define maxn 1000005
int f[maxn];

void getf(const char *p) {
	int len = strlen(p);
	memset(f, -1, sizeof f);
	for (int i = 0, j = -1; i < len;) {
		while (~j && p[i] != p[j]) j = f[j];
		i++; j++;
		f[i] = p[i] == p[j] ? f[j] : j;
	}
}

int kmp(const char *t, const char *p) {
	int len = strlen(t), lenp = strlen(p);
	getf(p);
	for (int i = 0, j = 0; i < len;) {
		while (~j && t[i] != p[j]) j = f[j];
		i++; j++;
		if (j == lenp) {
			return i - j;
			// j = 0;
		}
	}
	return -1;
}

class Solution {
public:
    int strStr(string haystack, string needle) {
		if (needle == "") return 0;
        return kmp(haystack.c_str(), needle.c_str());
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
        string haystack = stringToString(line);
        getline(cin, line);
        string needle = stringToString(line);
        
        int ret = Solution().strStr(haystack, needle);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
