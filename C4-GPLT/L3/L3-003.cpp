#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <vector>
#include <stdlib.h>
using namespace std;

int n, par[1005], cnt[1005], ans;
vector<int> h[1005];

int getfa(int x) { return (x == par[x] ? x : getfa(par[x])); }
void combine(int x, int y) { par[x] = par[y] = par[getfa(x)] = getfa(y); }

int main() {
	scanf("%d", &n);
	for (int i = 0; i < 1005; i++) par[i] = i;
	for (int i = 0; i < n; i++) {
		int k; scanf("%d:", &k);
		for (int j = 0; j < k; j++) {
			int v; scanf("%d", &v);
			h[i].push_back(v);
		}
		for (int j = 1; j < h[i].size(); j++)
			combine(h[i][j], h[i][0]);
	}

	for (int i = 0; i < n; i++) cnt[getfa(h[i][0])]++;
	sort(cnt, cnt + 1005);
	for (int i = 1004; ~i; i--)
		if (cnt[i] == 0) { ans = 1004 - i; break; }
	printf("%d\n%d", ans, cnt[1004]);
	for (int i = 1003; ~i; i--) {
		if (cnt[i] == 0) break;
		printf(" %d", cnt[i]);
	}
	return 0;
}
