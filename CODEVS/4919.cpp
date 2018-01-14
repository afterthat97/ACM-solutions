#include <cstring>
#include <stdio.h>

struct node {
    int addv, mod7[7], val;
    node(): addv(0){ memset(mod7, 0, sizeof mod7); }
};//root from 1

int n, a, b, m, _n;
node* tree;

void init() {
    _n = 1;
    while (_n < n) _n <<= 1;
    tree = new node[_n << 1];
    for (int i = _n; i < _n + n; i++) {
        scanf("%d", &tree[i].val);
        tree[i].mod7[tree[i].val % 7]++;
    }
    for (int p = _n >> 1; p > 0; p >>= 1)
        for (int i = p; i < (p << 1); i++) {
            int lc = i << 1, rc = (i << 1) + 1;
            for (int k = 0; k < 7; k++)
                tree[i].mod7[k] = tree[lc].mod7[k] + tree[rc].mod7[k];
        }
}

inline void maintain(int k, int l, int r) {
    int lt = k << 1, rt = (k << 1) + 1;
    if (r > l) {
        for (int t = 0; t < 7; t++)
            tree[k].mod7[(t + tree[k].addv) % 7] = tree[lt].mod7[t] + tree[rt].mod7[t];
    } else {
        for (int t = 0; t < 7; t++) tree[k].mod7[t] = 0;
        tree[k].mod7[(tree[k].val + tree[k].addv) % 7] = 1;
    }
}

void update(int k, int l, int r, int &v) {
    int lt = k << 1, rt = (k << 1) + 1;
    if (a <= l && b >= r)
        tree[k].addv = (tree[k].addv + v) % 7;
    else {
        int mid = (r + l) >> 1;
        if (a <= mid) update(lt, l, mid, v);
        if (mid < b) update(rt, mid + 1, r, v);
    }
    maintain(k, l, r);
}

int query(int k, int l, int r, int add) {
    if (r < a || l > b) return 0;
    if (a <= l && r <= b) return tree[k].mod7[(700000000 - add) % 7];
    else {
        int mid = (r + l) >> 1, lc = k << 1, rc = (k << 1) + 1;
        return query(lc, l, mid, add + tree[k].addv)
        + query(rc, mid + 1, r, add + tree[k].addv);
    }
}

int main() {
    scanf("%d", &n);
    init();
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        char opt[10];
        int v;
        scanf("%s", opt);
        if (opt[0] == 'a') {
            scanf("%d %d %d", &a, &b, &v);
            update(1, 1, _n, v);
        } else {
            scanf("%d %d", &a, &b);
            printf("%d\n", query(1, 1, _n, 0));
        }
    }
    delete[] tree;
    return 0;
}
