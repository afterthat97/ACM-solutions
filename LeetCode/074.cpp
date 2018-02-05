#include "all.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int tar) {
		if (a.size() == 0 || a[0].size() == 0) return false;
		int n = a.size(), m = a[0].size(), l = 0, r = n * m - 1;
		while (l < r) {
			int mid = (l + r) / 2;
			if (a[mid / m][mid % m] == tar)
				return true;
			else if (a[mid / m][mid % m] > tar)
				r = mid - 1;
			else
				l = mid + 1;
		}
		return a[l / m][l % m] == tar;
    }
};

int main() {
	int n, m; cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	int tar; cin >> tar;
	cout << Solution().searchMatrix(a, tar) << endl;
	return 0;
}
