#include "all.h"

typedef vector<vector<int>> vector2d;

class Solution {
public:
    int climbStairs(int n) {
        vector2d q { { 1, 1 }, { 1, 0 } };
		q = qpow(q, n);
		return q[1][0] + q[1][1];
    }
	vector2d qpow(vector2d q, int n) {
		vector2d ans { { 1, 0 }, { 0, 1 } };
		for (; n; n >>= 1) {
			if (n & 1) ans = mul(ans, q);
			q = mul(q, q);
		}
		return ans;
	}
	vector2d mul(vector2d& a, vector2d& b) {
		vector2d ans { { 0, 0 }, { 0, 0 } };
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				ans[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
		return ans;
	}
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().climbStairs(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
