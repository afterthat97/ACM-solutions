#include <iostream>
#include <stdio.h>
#include <cstring>
#include <set>
#define maxn 10005
using namespace std;

int par[maxn], rk[maxn];

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

int tot;

int main() {
	init();
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int k, x; cin >> k;
		if (k > 0) cin >> x;
		tot = max(tot, x);
		for (int j = 1; j < k; j++) {
			int y; cin >> y;
			tot = max(tot, y);
			combine(x, y);
		}
	}
	set<int> s;
	for (int i = 1; i <= tot; i++)
		s.insert(getfa(i));
	cout << tot << ' ' << s.size() << endl;
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int px, py; cin >> px >> py;
		puts(getfa(px) == getfa(py) ? "Y" : "N");
	}
	return 0;
}

