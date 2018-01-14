#include <iostream>
#include <stdio.h>
#include <set>
using namespace std;

set<int> s[51];
int n;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int k; cin >> k;
		for (int j = 0; j < k; j++) {
			int v; cin >> v;
			s[i].insert(v);
		}
	}

	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int x, y, same = 0; cin >> x >> y;
		for (set<int>::iterator it = s[x].begin(); it != s[x].end(); it++)
			if (s[y].find(*it) != s[y].end()) same++;
		printf("%.2f%%\n", (same * 100.0) / (s[x].size() + s[y].size() - same));
	}
	return 0;
}
