#include "all.h"

class Solution {
public:
    void nextPermutation(vector<int>& a) {
		int i = a.size() - 2;
		while ((i >= 0) && (a[i] >= a[i + 1])) i--;
		if (i < 0) {
			rev(&a[0], &a[a.size() - 1]);
			return;
		}
		int j = a.size() - 1;
		while (a[j] <= a[i]) j--;
		swap(a[j], a[i]);
		rev(&a[i + 1], &a[a.size() - 1]);
    }
	void rev(int* from, int* to) {
		while (from < to) {
			swap(*from, *to);
			from++; to--;
		}
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

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        Solution().nextPermutation(nums);

        string out = integerVectorToString(nums);
        cout << out << endl;
    }
    return 0;
}
