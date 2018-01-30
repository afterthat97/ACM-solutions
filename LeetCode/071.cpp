#include "all.h"

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> s;
		string tmp; stringstream ss(path);
		while (getline(ss, tmp, '/')) {
			if (tmp == "" || tmp == ".") continue;
			if (tmp == ".." && s.size()) { s.pop_back(); continue; }
			if (tmp != "..") s.push_back(tmp);
		}
		string ans;
		for (int i = 0; i < s.size(); i++)
			ans += "/" + s[i];
		return ans.empty() ? "/" : ans;
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
        string path = stringToString(line);
        
        string ret = Solution().simplifyPath(path);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
