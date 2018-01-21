#include "all.h"

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size(), m = nums2.size();
		if (n > m) {
			swap(n, m);
			swap(nums1, nums2);
		}
		int l = 0, r = n + 1;
		while (l <= r) {
			int i = (l + r) / 2, j = (m + n + 1) / 2 - i;
			if (i > 0 && nums1[i - 1] > nums2[j]) // i is big
				r = i - 1;
			else if (i < n && nums2[j - 1] > nums1[i]) // i is small
				l = i + 1;
			else { // got it
				int ansl = 0, ansr = 0;
				if (i == 0) ansl = nums2[j - 1];
				else if (j == 0) ansl = nums1[i - 1];
				else ansl = max(nums1[i - 1], nums2[j - 1]);
				if ((m + n) % 2) return ansl;
				if (i == n) ansr = nums2[j];
				else if (j == m) ansr = nums1[i];
				else ansr = min(nums1[i], nums2[j]);
				return (ansl + ansr) / 2.0;
			}
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums1 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> nums2 = stringToIntegerVector(line);
        
        double ret = Solution().findMedianSortedArrays(nums1, nums2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
