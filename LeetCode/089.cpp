#include "all.h"

class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 0) return vector<int> { 0 };
		vector<int> ans = grayCode(n - 1);
		for (int i = ans.size() - 1; ~i; i--)
			ans.push_back((1 << (n - 1)) + ans[i]);
		return ans;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        vector<int> ret = Solution().grayCode(n);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
