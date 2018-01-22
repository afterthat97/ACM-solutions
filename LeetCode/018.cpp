#include "all.h"

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int target) {
		typedef pair<int, int> P;
		unordered_map<int, vector<P> > table;
		sort(a.begin(), a.end());
		int n = a.size();
		vector<vector<int>> ans;
		if (n < 4) return ans;
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				table[a[i] + a[j]].push_back(P(i, j));
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				if (table[target - a[i] - a[j]].size()) {
					int tar = target - a[i] - a[j];
					int m = table[tar].size();
					for (int k = 0; k < m; k++) {
						if (table[tar][k].first == i || table[tar][k].second == i
						 || table[tar][k].first == j || table[tar][k].second == j)
							continue;
						vector<int> cas { a[i], a[j], a[table[tar][k].first], a[table[tar][k].second] };
						sort(cas.begin(), cas.end());
						ans.push_back(cas);
					};
				}
		sort(ans.begin(), ans.end());
		ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        
        vector<vector<int>> ret = Solution().fourSum(nums, target);

		for (int i = 0; i < ret.size(); i++) {
			for (int j = 0; j < ret[i].size(); j++)
				cout << ret[i][j] << ' ';
			cout << endl;
		}
    }
    return 0;
}
