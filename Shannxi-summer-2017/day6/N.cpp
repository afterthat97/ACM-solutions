#include <iostream>
#include <stdio.h>
#include <cstring>
#define maxn 55
#define ll long long
using namespace std;

int par[maxn], rk[maxn], tot[maxn];

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

ll pow(ll n, int k) {
	ll ans = 1;
	for (int i = 0; i < k; i++)
		ans *= n;
	return ans;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	init();
	for (int i = 0; i < m; i++) {
		int px, py;
		scanf("%d %d", &px, &py);
		combine(px, py);
	}
	for (int i = 1; i <= n; i++)
		tot[getfa(i)]++;
	ll ans = 1;
	for (int i = 1; i <= n; i++)
		ans *= pow(2, tot[i] - 1);
	cout << ans << endl;
	return 0;
}

