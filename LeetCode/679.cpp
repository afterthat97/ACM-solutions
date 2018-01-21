#include "all.h"

bool judge(vector<double> nums) {
	if (nums.size() == 1)
		return fabs(nums[0] - 24.0f) < 1e-6;
	for (int i = 0; i < nums.size(); i++)
		for (int j = 0; j < nums.size(); j++) {
			if (i == j) continue;
			vector<double> newNums;
			for (int k = 0; k < nums.size(); k++)
				if (k != i && k != j)
					newNums.push_back(nums[k]);
			newNums.push_back(0.0f);
			for (int k = 0; k < 4; k++) {
				if (k == 0) newNums[nums.size() - 2] = nums[i] + nums[j];
				if (k == 1) newNums[nums.size() - 2] = nums[i] - nums[j];
				if (k == 2) newNums[nums.size() - 2] = nums[i] * nums[j];
				if (k == 3) {
					if (fabs(nums[j]) < 1e-7) continue;
					newNums[nums.size() - 2] = nums[i] / nums[j];
				}
				if (judge(newNums)) return true;
			}
		}
	return false;
}

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
		vector<double> tmp;
		for (int i = 0; i < nums.size(); i++)
			tmp.push_back(nums[i] * 1.0f);
		return judge(tmp);
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
        
        bool ret = Solution().judgePoint24(nums);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
