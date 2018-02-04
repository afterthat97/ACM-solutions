#include "all.h"

class Solution {
public:
	void setZeroes(vector<vector<int> > &matrix) {
		int col0 = 1, rows = matrix.size(), cols = matrix[0].size();
		for (int i = 0; i < rows; i++) {
			if (matrix[i][0] == 0) col0 = 0;
			for (int j = 1; j < cols; j++)
				if (matrix[i][j] == 0)
					matrix[i][0] = matrix[0][j] = 0;
		}
		for (int i = rows - 1; ~i; i--) {
			for (int j = 1; j < cols; j++)
				if (matrix[i][0] == 0 || matrix[0][j] == 0)
					matrix[i][j] = 0;
			if (col0 == 0) matrix[i][0] = 0;
		}
	}
};

int main() {
	int n, m; cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	Solution().setZeroes(a);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << a[i][j] << ' ';
		cout << endl;
	}
	return 0;
}
