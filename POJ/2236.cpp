#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
#include <vector>
#define maxn 1005
#define ll long long
using namespace std;

pair<int, int> coord[maxn];
vector<int> near[maxn];
int par[maxn], rk[maxn], n;
bool online[maxn];
ll d;

int getfa(int x) {
	int fx = x;
	while (fx != par[fx]) fx = par[fx];
	while (x != fx) {
		int tmp = par[x];
		par[x] = fx;
		x = tmp;
	}
	return fx;
}

void link(int x, int y) {
    x = getfa(x); y = getfa(y);
    if (rk[x] > rk[y]) {
        par[y] = x;
    } else {
        par[x] = y;
        if (rk[x] == rk[y]) rk[y]++;
    }
}

ll getdis2(pair<int, int> a, pair<int, int> b) {
    ll dx = a.first - b.first;
    ll dy = a.second - b.second;
    return dx * dx + dy * dy;
}

int main() {
    scanf("%d %lld", &n, &d);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &coord[i].first, &coord[i].second);
        par[i] = i;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (getdis2(coord[i], coord[j]) <= d * d)
                near[i].push_back(j);
        }

    char opt;
    while (scanf(" %c", &opt) != EOF) {
        if (opt == 'O') { // repair
            int t; scanf("%d", &t);
            online[t] = true;
            for (int i = 0; i < near[t].size(); i++)
                if (online[near[t][i]])
                    link(t, near[t][i]);
        } else {
            int x, y; scanf("%d %d", &x, &y);
            puts(getfa(x) == getfa(y) ? "SUCCESS" : "FAIL");
        }
    }
    return 0;
}
