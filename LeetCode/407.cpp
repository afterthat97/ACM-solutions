#include "all.h"

struct cell {
	int h, x, y;
};

struct cmp {
	bool operator () (const cell& a, const cell& b) {
		return a.h > b.h;
	}
};

class Solution {
public:
	const int dx[4] = { 1, 0, -1, 0 };
	const int dy[4] = { 0, 1, 0, -1 };
    int trapRainWater(vector<vector<int>>& h) {
		if (!h.size() || !h[0].size()) return 0;
        priority_queue<cell, vector<cell>, cmp> q;
		vector<vector<bool>> vis(h.size());
		int n = h.size(), m = h[0].size();
		for (int i = 0; i < n; i++) vis[i].resize(m);
		for (int i = 0; i < n; i++) {
			vis[i][0] = vis[i][m - 1] = 1;
			q.push({ h[i][0], i, 0 });
			q.push({ h[i][m - 1], i, m - 1 });
		}
		for (int j = 1; j < m - 1; j++) {
			vis[0][j] = vis[n - 1][j] = 1;
			q.push({ h[0][j], 0, j });
			q.push({ h[n - 1][j], n - 1, j });
		}
		int ans = 0;
		while (!q.empty()) {
			cell now = q.top(); q.pop();
			for (int k = 0; k < 4; k++) {
				int nx = now.x + dx[k], ny = now.y + dy[k];
				if (nx < 0 || ny < 0 || nx == n || ny == m) continue;
				if (vis[nx][ny]) continue;
				vis[nx][ny] = 1;
				ans += max(h[nx][ny], now.h) - h[nx][ny];
				q.push({ max(h[nx][ny], now.h), nx, ny });
			}
		}
		return ans;
    }
};

int main() {
	int n, m; cin >> n >> m;
	vector<vector<int>> h(n);
	for (int i = 0; i < n; i++) {
		h[i].resize(m);
		for (int j = 0; j < m; j++)
			cin >> h[i][j];
	}
	cout << Solution().trapRainWater(h) << endl;
	return 0;
}
