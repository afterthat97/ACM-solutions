#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <stdlib.h>
using namespace std;

const int maxn = 505;
int np, ne, edges[5005][2], par[maxn], rk[maxn];
bool lost[maxn];

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

int check() {
	for (int i = 0; i < maxn; i++) par[i] = i;
	for (int i = 0; i < ne; i++)
		if (!lost[edges[i][0]] && !lost[edges[i][1]])
			combine(edges[i][0], edges[i][1]);
	bool cnt[maxn] = {};
	for (int i = 0; i < np; i++)
		if (!lost[i]) cnt[getfa(i)] = 1;
	int ans = 0;
	for (int i = 0; i < np; i++)
		ans += cnt[i];
	return ans;
}

int main() {
	for (int i = 0; i < maxn; i++) par[i] = i;
	cin >> np >> ne;
	for (int i = 0; i < ne; i++)
		scanf("%d %d", &edges[i][0], &edges[i][1]);
	int T; cin >> T;
	int b = check();
	for (int idx = 0; idx < T; idx++) {
		int p; cin >> p;
		lost[p] = 1;
		int now = check();
		if (now > b) printf("Red Alert: City %d is lost!\n", p);
		else printf("City %d is lost.\n", p);
		if (idx + 1 == np) printf("Game Over.");
		b = now;
	}
	return 0;
}
