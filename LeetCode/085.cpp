#include "all.h"

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& a) {
        if (a.size() == 0 || a[0].size() == 0) return 0;
		int n = a.size(), m = a[0].size(), ans = 0;
		vector<int> h(m + 1, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				h[j] = a[i][j] == '1' ? h[j] + 1 : 0;
			ans = max(ans, largestRectangleArea(h));
		}
		return ans;
    }
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
		h.pop_back();
		return ans;
    }
};

int main() {
	int n, m; cin >> n >> m;
	vector<vector<char>> a(n, vector<char>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	cout << Solution().maximalRectangle(a) << endl;
	return 0;
}
