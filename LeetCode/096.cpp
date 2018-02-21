#include "all.h"

class Solution {
public:
    int numTrees(int n) {
		vector<int> f(n + 1, 0);
		f[0] = f[1] = 1;
		for (int i = 2; i <= n; i++)
			for (int j = 0; j < i; j++)
				f[i] += f[j] * f[i - j - 1];
		return f[n];
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().numTrees(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
