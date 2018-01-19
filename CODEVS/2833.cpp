#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int np, ne;
int in_degree[10001];
vector <int> g[10005];

void topologic() {
	int cnt = 0;
	int* toposort = new int[np];
	queue<int> q;
	for (int i = 1; i <= np; i++)
		if (in_degree[i] == 0)
			q.push(i);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		toposort[cnt++] = cur;
		for (int i = 0; i < g[cur].size(); i++) {
			in_degree[g[cur][i]]--;
			if (in_degree[g[cur][i]] == 0)
				q.push(g[cur][i]);
		}
	}
	if (cnt != np) {
		cout << "T_T" << endl << np - cnt;
	} else cout << "o(กษ_กษ)o" << endl;
}

int main() {
	cin >> np >> ne;
	for (int i = 1; i <= ne; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].push_back(y);
		in_degree[y]++;
	}
	topologic();
	return 0;
}
