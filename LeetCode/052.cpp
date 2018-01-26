#include "all.h"

class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        vector<int> used1(n * 2, 0), used2(n * 2, 0), usedCol(n, 0);
        solve(ans, used1, used2, usedCol, n - 1, n);
        return ans;
    }
    void solve(int& ans, vector<int> used1, vector<int> used2, vector<int> usedCol, int k, int n) {
        if (k == -1) {
            ans++;
        } else {
            for (int i = 0; i < n; i++) {
                if (usedCol[i] || used1[i + k] || used2[n + i - k]) continue;
                usedCol[i] = 1; used1[i + k] = 1; used2[n + i - k] = 1;
                solve(ans, used1, used2, usedCol, k - 1, n);
                usedCol[i] = 0; used1[i + k] = 0; used2[n + i - k] = 0;
            }
        }
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().totalNQueens(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
