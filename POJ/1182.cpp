#include <iostream>
#include <stdio.h>
#define maxn 150005
using namespace std;

int par[maxn], rk[maxn], n, k;

int getfa(int x) {
    return x == par[x] ? x : getfa(par[x]);
}

void link(int x, int y) {
    x = getfa(x); y = getfa(y);
    if (x == y) return;
    if (rk[x] < rk[y]) {
        par[x] = y;
    } else {
        par[y] = x;
        if (rk[x] == rk[y]) rk[x]++;
    }
}

int main() {
    for (int i = 0; i < maxn; i++)
        par[i] = i;
    scanf("%d %d", &n, &k);
    int wrong = 0;
    for (int i = 0; i < k; i++) {
        int opt, x, y;
        scanf("%d %d %d", &opt, &x, &y);
        x--; y--;
        if (x >= n || y >= n) {
            wrong++;
            continue;
        }
        if (opt == 1) { // same
            if (getfa(x) == getfa(y + n) || getfa(x + n) == getfa(y)) {
                wrong++;
                continue;
            }
            link(x, y);
            link(x + n, y + n);
            link(x + 2 * n, y + 2 * n);
        } else { // x eat y
            if (getfa(x) == getfa(y) || getfa(x + n) == getfa(y)) {
                wrong++;
                continue;
            }
            link(x, y + n);
            link(x + n, y + 2 * n);
            link(x + 2 * n, y);
        }
    }
    printf("%d\n", wrong);
    return 0;
}
