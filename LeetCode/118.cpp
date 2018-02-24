#include "all.h"

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ans;
		for (int i = 0; i < numRows; i++) {
			vector<int> cnt(i + 1, 1);
			ans.push_back(cnt);
			for (int j = 1; j < i; j++)
				ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
		}
        return ans;
    }
};

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
	int n;
	while (cin >> n) {
		vector<vector<int>> ret = Solution().generate(n);
		
		cout << '[' << endl;
		for (int i = 0; i < ret.size(); i++) {
			string out = integerVectorToString(ret[i]);
			cout << "  " << out << ',' << endl;
		}
		cout << ']' << endl;
	}
}
