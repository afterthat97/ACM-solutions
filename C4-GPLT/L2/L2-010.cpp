#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <stdlib.h>
using namespace std;

int n, m, k;
bool off[105][105];
int par[105], rk[105];

void init() {
	memset(rk, 0, sizeof rk);
	for (int i = 0; i < 105; i++) par[i] = i;
}

inline int getfa(int x) {
	int fx = x;
	while (fx != par[fx]) fx = par[fx];
	while (x != fx) {
		int tmp = par[x];
		par[x] = fx;
		x = tmp;
	}
	return fx;
}

inline void combine(int x, int y) {
	if (rk[x = getfa(x)] > rk[y = getfa(y)])
		par[y] = x;
	else {
		par[x] = y;
		if (rk[x] == rk[y]) rk[y]++;
	}
}

int main() {
	init();
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int x, y, v;
		scanf("%d %d %d", &x, &y, &v);
		if (v == 1) combine(x, y);
		else off[x][y] = off[y][x] = 1;
	}

	for (int i = 0; i < k; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		int fx = getfa(x), fy = getfa(y);
		if (fx == fy && !off[x][y]) puts("No problem");
		else if (fx == fy && off[x][y]) puts("OK but...");
		else if (fx != fy && !off[x][y]) puts("OK");
		else puts("No way");
	}
	return 0;
}
