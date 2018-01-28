#include "all.h"

class Solution {
public:
    string getPermutation(int n, int k) {
		--k;
		string str; str.resize(n);
		int used[10] = {}, jc[10] = { 1 };
		for (int i = 1; i < 10; i++) jc[i] = jc[i - 1] * i;
		for (int i = 0; i < str.size(); i++) {
			int divk = k / jc[n - i - 1], modk = k % jc[n - i - 1];
			for (int j = 1; j <= n; j++) {
				if (used[j]) continue;
				if (divk == 0) {
					str[i] = j + '0';
					used[j] = 1;
					break;
				} else divk--;
			}
			k = modk;
		}
		return str;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        string ret = Solution().getPermutation(n, k);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
