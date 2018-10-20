#include "all.h"

class Solution {
public:
    bool is_alphanum(char ch) {
        if (ch >= '0' && ch <= '9') return true;
        if (ch >= 'a' && ch <= 'z') return true;
        if (ch >= 'A' && ch <= 'Z') return true;
        return false;
    }
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (!is_alphanum(s[l])) {
                l++;
                if (l == s.size()) return true;
            }
            while (!is_alphanum(s[r])) {
                r--;
                if (r == -1) return true;
            }
            if (s[l] >= 'a' && s[l] <= 'z') s[l] = s[l] - 'a' + 'A';
            if (s[r] >= 'a' && s[r] <= 'z') s[r] = s[r] - 'a' + 'A';
            if (s[l] != s[r]) return false;
            l++; r--;
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
        string s = stringToString(line);
        
        bool ret = Solution().isPalindrome(s);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
