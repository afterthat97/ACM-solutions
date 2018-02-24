#include "all.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
		if (prices.size() == 0) return 0;
		int tot = 0;
		vector<int> l(prices.size(), 0), r(prices.size(), 0);
		for (int i = 0, ans = 0, minn = INT_MAX; i < prices.size(); i++) {
			if (prices[i] < minn) minn = prices[i];
			l[i] = ans = max(ans, prices[i] - minn);
		}
		for (int i = prices.size() - 1, ans = 0, maxx = INT_MIN; ~i; i--) {
			if (prices[i] > maxx) maxx = prices[i];
			r[i] = ans = max(ans, maxx - prices[i]);
		}
		for (int i = 0; i < prices.size() - 1; i++)
			tot = max(tot, l[i] + r[i + 1]);
		return max(tot, l[l.size() - 1]);
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> prices = stringToIntegerVector(line);
        
        int ret = Solution().maxProfit(prices);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
