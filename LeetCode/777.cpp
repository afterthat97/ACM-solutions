#include "all.h"

#define fst first
#define snd second
class Solution {
public:
    bool canTransform(string str1, string str2) {
		int maxl = max(str1.size(), str2.size()) + 1;
		vector<pair<char, int> > idx1, idx2;
		if (str1.size() != str2.size()) return false;
		for (int i = 0; i < str1.size(); i++) {
			if (str1[i] != 'X') idx1.push_back(pair<char, int>(str1[i], i));
			if (str2[i] != 'X') idx2.push_back(pair<char, int>(str2[i], i));
		}
		if (idx1.size() != idx2.size()) return false;
		for (int i = 0; i < idx1.size(); i++) {
			if (idx1[i].fst != idx2[i].fst) return false;
			if (idx1[i].fst == 'L' && idx2[i].snd > idx1[i].snd) return false;
			if (idx1[i].fst == 'R' && idx2[i].snd < idx1[i].snd) return false;
		}
		return true;
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
        string start = stringToString(line);
        getline(cin, line);
        string end = stringToString(line);
        
        bool ret = Solution().canTransform(start, end);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
