#include "all.h"

class Solution {
public:
    void rotate(vector<vector<int>>& a) {
		int n = a.size();
		if (n < 2) return;
		for (int i = 0; i < n / 2; i++)
			for (int j = i; j < n - i - 1; j++) {
				int last = a[i][j], x = i, y = j;
				for (int k = 0; k < 3; k++) {
					a[x][y] = a[n - y - 1][x];
					int tmp = x; x = n - y - 1; y = tmp;
				}
				a[x][y] = last;
			}
    }
};

int main() {
	int n; cin >> n;
	vector<vector<int>> mat(n);
	for (int i = 0; i < n; i++) {
		mat[i].resize(n);
		for (int j = 0; j < n; j++)
			cin >> mat[i][j];
	}
	Solution().rotate(mat);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << mat[i][j] << ' ';
		cout << endl;
	}
	return 0;
}
