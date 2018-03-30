#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#define maxn 505
using namespace std;

int color[maxn], np, ne, k;
vector<pair<int, int>> g;

bool check() {
	set<int> s;
	for (int i = 1; i <= np; i++)
		s.insert(color[i]);
	if (s.size() != k) return false;
	for (int i = 0; i < g.size(); i++) {
		int px = g[i].first;
		int py = g[i].second;
		if (color[px] == color[py]) return false;
	}
	return true;
}

int main() {
	cin >> np >> ne >> k;
	for (int i = 0; i < ne; i++) {
		int px, py;
		cin >> px >> py;
		g.push_back(pair<int, int>(px, py));
	}
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 1; j <= np; j++)
			cin >> color[j];
		cout << (check() ? "Yes" : "No") << endl;
	}
	return 0;
}
