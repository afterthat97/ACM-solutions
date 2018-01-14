#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#define INF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define fst first
#define snd second
using namespace std;

typedef pair<double, ll> info;
struct node {
    vector<info> dat;
    vector<ll> sum;
};

int n, m, _n, x, y;
node *tree;
ll g[1005][1005];

void init() {
    _n = 1;
    while (_n < n) _n <<= 1;
    tree = new node[_n << 1];
    for (int i = _n; i < _n + n; i++) {
        tree[i].dat.resize(n + 1);
        tree[i].sum.resize(n + 1);
        tree[i].sum[0] = 0;
		for (int j = 1; j <= n; j++) {
            tree[i].dat[j].fst = (j * 1.0) / (i - _n + 1);
            tree[i].dat[j].snd = g[n - j + 1][i - _n + 1];
            tree[i].sum[j] = tree[i].sum[j - 1] + tree[i].dat[j].snd;
        }
    }
    int p = _n;
    while (p > 1) {
        p >>= 1;
        for (int i = p; i < (p << 1); i++) {
            int lc = i << 1, rc = (i << 1) + 1;
            tree[i].dat.resize(tree[lc].dat.size() + tree[rc].dat.size());
            tree[i].sum.resize(tree[lc].dat.size() + tree[rc].dat.size());
            if (tree[i].sum.size() == 0) continue;
            merge(tree[lc].dat.begin(), tree[lc].dat.end(),
                  tree[rc].dat.begin(), tree[rc].dat.end(),
                  tree[i].dat.begin());
            tree[i].sum[0] = 0;
            for (int j = 1; j < tree[i].sum.size(); j++)
                tree[i].sum[j] = tree[i].sum[j - 1] + tree[i].dat[j].snd;
        }
    }
}

ll query(int l, int r, int t, double k) {
    if (r < 1 || l > x) return 0;
    if (1 <= l && r <= x) {
        int idx = upper_bound(tree[t].dat.begin(), tree[t].dat.end(),
                              info(k, INF)) - tree[t].dat.begin();
        return tree[t].sum[idx - 1];
    } else {
        int mid = (l + r) >> 1, lc = t << 1, rc = (t << 1) + 1;
        return query(l, mid, lc, k) + query(mid + 1, r, rc, k);
    }
}

int main() {
    int T; scanf("%d", &T);
    for (int idx = 1; idx <= T; idx++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                scanf("%lld", &g[i][j]);
        init();
        scanf("%d", &m);
        printf("Case #%d:\n", idx);
		for (int i = 0; i < m; i++) {
            scanf("%d %d", &x, &y);
            printf("%lld\n", query(1, _n, 1, ((y) * 1.0) / (x)));
        }
        delete[] tree;
    }
    return 0;
}
