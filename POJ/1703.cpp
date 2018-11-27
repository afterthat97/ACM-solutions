#include <iostream>
#include <stdio.h>
#define maxn 200005
using namespace std;

int par[maxn], rk[maxn];
int T, n, m;

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
    cin >> T;
    while (T--) {
        for (int i = 0; i < maxn; i++)
            par[i] = i;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; i++) {
            char opt; int x, y;
            scanf(" %c %d %d", &opt, &x, &y);
            if (opt == 'A') {
                if (getfa(x) == getfa(y))
                    puts("In the same gang.");
                else if (getfa(x) == getfa(y + n))
                    puts("In different gangs.");
                else
                    puts("Not sure yet.");
            } else {
                link(x, y + n);
                link(x + n, y);
            }
        }
    }
    return 0;
}
