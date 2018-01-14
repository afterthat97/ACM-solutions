#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <stdlib.h>
#define maxn 20005
using namespace std;

struct edge {
	int x, y, w;
}e[100005];
vector<int> g[maxn];

bool cmp(edge &a, edge &b) {	
	return a.w > b.w;
}	

int par[maxn];

int getfa(int x) { return (x == par[x] ? x : getfa(par[x])); }

void combine(int x, int y) {
	par[x] = par[y] = par[getfa(x)] = getfa(y);
}

int main() {
	int T; scanf("%d",  &T);
	int n, m;
	for (int idx = 0; idx < T; idx++) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i <= n; i++) {
			par[i] = i;
			g[i].resize(0);
		}
		for (int i = 0; i < m; i++)
			scanf("%d %d %d", &e[i].x, &e[i].y, &e[i].w);
		sort(e, e + m, cmp);
		int i;
		for (i = 0; i < m; i++) {
			if (getfa(e[i].x) == getfa(e[i].y)) {
				printf("Case #%d:\n%d\n", idx + 1, e[i].w);
				break;
			}
			for (int j = 0; j < g[e[i].x].size(); j++)
				combine(g[e[i].x][j], e[i].y);
			for (int j = 0; j < g[e[i].y].size(); j++)
				combine(g[e[i].y][j], e[i].x);
			g[e[i].x].push_back(e[i].y);
			g[e[i].y].push_back(e[i].x);
		}
		if (i == m) 
			printf("Case #%d:\n%d\n", idx + 1, 0);
	}	
    return 0;
}
