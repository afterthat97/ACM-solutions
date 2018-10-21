#include <iostream>
#include <stdio.h>
#include <bitset>
#define maxr 12
#define maxc 10010
using namespace std;

bitset<maxc> a[maxr];
int r, c, ans;

void dfs(int k) {
    if (k == -1) {
        int tot = 0;
        for (int i = 0; i < c; i++) {
            int totr = 0;
            for (int j = 0; j < r; j++)
                if (a[j][i]) totr++;
            tot += max(totr, r - totr);
        }
        ans = max(ans, tot);
        return;
    }
    dfs(k - 1);
    a[k].flip();
    dfs(k - 1);
}

int main() {
    while (scanf("%d %d", &r, &c) == 2 && r && c) {
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) {
                int tmp; scanf("%d", &tmp);
                a[i][j] = bool(tmp);
            }
        ans = 0;
        dfs(r - 1);
        printf("%d\n", ans);
    }
    return 0;
}
