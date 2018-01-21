#include "all.h"

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
		if (nums.size() == 0) return false;
		stack<int> s;
		s.push(0);
		vector<int> minl;
		minl.resize(nums.size());
		minl[0] = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			minl[i] = min(minl[i - 1], nums[i]);
			if (nums[i] < nums[i - 1]) {
				if (i > 1 && minl[i - 2] < nums[i]) return true;
			} else {
				while (!s.empty() && nums[s.top()] <= nums[i]) s.pop();
				if (!s.empty() && s.top() && minl[s.top() - 1] < nums[i]) return true;
			}
			s.push(i);
		}
		return false;
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        bool ret = Solution().find132pattern(nums);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
