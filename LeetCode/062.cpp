#include "all.h"

class Solution {
public:
    int uniquePaths(int m, int n) {
        return C(m + n - 2, m - 1);
    }
	double C(int n, int k) {
		double ans = 1;
		for (int i = 1; i <= k; i++)
			ans = ans * (n - k + i) / i;
		return ans;
	}
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int m = stringToInteger(line);
        getline(cin, line);
        int n = stringToInteger(line);
        
        int ret = Solution().uniquePaths(m, n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
