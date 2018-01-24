#include "all.h"

class Solution {
public:
    string countAndSay(int n) {    
		if (n == 0) return "";
		string res = "1";
		while (--n) {
			string cur = "";
			for (int i = 0; i < res.size(); i++) {
				int count = 1;
				while (i < res.size() - 1 && res[i] == res[i + 1]) {
					count++; i++;
				}
				cur += to_string(count) + res[i];
			}
			res = cur;
		}
		return res;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        string ret = Solution().countAndSay(n);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
