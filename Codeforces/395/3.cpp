#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;


vector<int> g[100005];
int n;
int c[100005];
int degree[100005];

bool dfs(int from, int to, int col) {
	for (int i = 0; i < g[to].size(); i++)
		if (g[to][i] != from) {
			if (c[g[to][i]] == col) {
				if (!dfs(to, g[to][i], col)) return 0; }
			else
				return 0;
		}
	return 1;
}

int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int px, py;
		scanf("%d %d", &px, &py);
		degree[px]++;
		degree[py]++;
		g[px].push_back(py);
		g[py].push_back(px);
	}
	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	queue<int> q;

	for (int i = 1; i <= n; i++)
		if (degree[i] == 1) q.push(i);

	bool dead[100005] = {};
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < g[now].size(); i++)
			if (!dead[g[now][i]]) {
				int to = g[now][i];
				if (c[to] == c[now]) {
					degree[to]--;
					dead[now] = 1;
					if (degree[to] == 1) q.push(to);
				} else {
					int col = c[now];
					for (int i = 0; i < g[to].size(); i++)
						if (!dead[g[to][i]] && g[to][i] != now) {
							col = c[g[to][i]];
							if (!dfs(to, g[to][i], col)) {
								cout << "NO";
								return 0;
							}
						}
					cout << "YES\n" << to;
					return 0;
				}
			}
	}
	cout << "YES\n1";
	return 0;
}
