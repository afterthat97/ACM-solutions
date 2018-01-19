#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <vector>
#include <ctime>
#include <sstream>
#include <deque>
#include <functional>
#include <iterator>
#include <list>
#include <memory>
#include <numeric>
#include <utility>

#define INF 999999999
#define ll long long;
#define ull unsigned long long;
#define pause cin.get();cin.get();
#define read(i) scanf("%d", &i);
#define ln printf("\n");
using namespace std;

struct node {
	int x, y, t;
	node(int x, int y, int t):x(x), y(y), t(t) {};
};

const int dx[4] = { 0,1,0,-1 };
const int dy[4] = { 1,0,-1,0 };

pair <int, int> danger[101][101];
int n, m, t, maxt;
queue<node> q;
bool h[101][101][300];

bool can(int x, int y, int t) {
	if (x > n || y > m || x < 1 || y < 1)
		return false;
	if (danger[x][y].first <= t && t <= danger[x][y].second)
		return false;
	return true;
}

int main() {
	scanf("%d %d %d", &n, &m, &t);
	for (int i = 0; i < t; i++) {
		int x, y, a, b;
		scanf("%d %d %d %d", &x, &y, &a, &b);
		if (b > maxt) maxt = b;
		danger[x][y].first = a;
		danger[x][y].second = b;
	}

	int ans = 99999;
	q.push(node(1, 1, 0));
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		if (now.t == maxt) {
			if (now.t + n - now.x + m - now.y < ans)
				ans = now.t + n - now.x + m - now.y;
			continue;
		}
		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			if (can(nx, ny, now.t + 1))
				if (!h[nx][ny][now.t + 1]) {
					if (nx == n && ny == m) {
						cout << now.t + 1;
						return 0;
					}
					h[nx][ny][now.t + 1] = 1;
					q.push(node(nx, ny, now.t + 1));
				}
		}
	}

	cout << ans;
	system("pause");
	return 0;
}
