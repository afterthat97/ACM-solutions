#include "all.h"

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > nums.size() || nums[i] <= 0) continue;
			for (int k = nums[i]; nums[k - 1] != k; k = nums[i]) {
				swap(nums[k - 1], nums[i]);
				if (nums[i] > nums.size() || nums[i] <= 0) break;
			}
		}
		for (int i = 0; i < nums.size(); i++)
			if (nums[i] != i + 1) return i + 1;
		return nums.size() + 1;
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
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().firstMissingPositive(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
