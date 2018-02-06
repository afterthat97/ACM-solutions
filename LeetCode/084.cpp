#include "all.h"

class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int ans = 0;
		stack<int> s; s.push(-1);
		h.push_back(0);
		for (int i = 0; i < h.size(); i++)
			if (s.empty() || h[s.top()] < h[i]) s.push(i);
			else {
				while (!s.empty() && s.top() != -1 && h[s.top()] >= h[i]) {
					int cnt = s.top(); s.pop();
					ans = max(ans, (i - s.top() - 1) * h[cnt]);
				}
				s.push(i);
			}
		return ans;
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
        vector<int> heights = stringToIntegerVector(line);
        
        int ret = Solution().largestRectangleArea(heights);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
