#include "all.h"

class Solution {
public:
    int minSteps(int n) {
		if (n == 1) return 0;
		for (int i = 2; i * i <= n; i++)
			if (n % i == 0)
				return minSteps(n / i) + i;
		return n;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().minSteps(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
