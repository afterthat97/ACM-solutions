#include "all.h"

vector<string> M {"", "M", "MM", "MMM"};
vector<string> C {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
vector<string> X {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
vector<string> I {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

class Solution {
public:
    string intToRoman(int num) {
		return M[num / 1000]
			+ C[(num % 1000) / 100]
			+ X[(num % 100) / 10]
			+ I[num % 10];
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int num = stringToInteger(line);
        
        string ret = Solution().intToRoman(num);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
