#include "all.h"

class Solution {
public:
    int kthGrammar(int n, int k) {
		if (n == 1) return 0;
        if (kthGrammar(n - 1, (k + 1) / 2) == 1)
			return k & 1;
		else
			return !(k & 1);
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int N = stringToInteger(line);
        getline(cin, line);
        int K = stringToInteger(line);
        
        int ret = Solution().kthGrammar(N, K);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
