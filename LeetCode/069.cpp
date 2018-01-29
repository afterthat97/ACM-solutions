#include "all.h"

class Solution {
public:
    int mySqrt(int x) {
		long long ans = 1;
        for (; ans * ans <= (long long)x; ans++);
		return ans - 1;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        
        int ret = Solution().mySqrt(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
