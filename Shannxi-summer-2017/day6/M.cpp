#include <iostream>
#include <stdio.h>
#include <cstring>
#include <map>
#define maxn 200005
using namespace std;

int par[maxn], rk[maxn], c[maxn], num[maxn], maxc[maxn];
map<int, int> tot[maxn];

void init() {
	memset(rk, 0, sizeof rk);
	for (int i = 0; i < maxn; i++) par[i] = i;
}

inline int getfa(int x) {
	int fx = x, tmp;
	while (fx != par[fx]) fx = par[fx];
	while (x != fx) {//compress condition
		tmp = par[x];
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
	int n, m, k;
	init();
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	for (int i = 0; i < m; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		combine(l, r);
	}
	for (int i = 1; i <= n; i++) {
		int fa = getfa(i);
		maxc[fa] = max(++tot[fa][c[i]], maxc[fa]);
		num[fa]++;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) 
		ans += num[i] - maxc[i];
	cout << ans << endl;
	return 0;
}

