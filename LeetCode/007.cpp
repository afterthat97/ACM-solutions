#include "all.h"

class Solution {
public:
    int reverse(int x) {
		bool flag = 0;
		if (x < 0) { flag = 1; x = -x; }
		if (x < 0) return 0;
		while (x && x % 10 == 0) x /= 10;
		long long ans = 0;
		while (x) {
			ans *= 10;
			ans += x % 10;
			x /= 10;
		}
		if (ans > INT32_MAX) return 0;
		return flag ? -ans : ans;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        
        int ret = Solution().reverse(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
