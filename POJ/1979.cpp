#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int n, m, map[25][25], stx, sty;
bool vis[25][25];

void dfs(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) return;
    if (vis[x][y] || map[x][y]) return;
    vis[x][y] = true;
    for (int k = 0; k < 4; k++)
        dfs(x + dx[k], y + dy[k]);
}

int main() {
    while (scanf("%d %d", &m, &n) == 2 && n && m) {
        memset(vis, 0, sizeof vis);
        memset(map, 0, sizeof map);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                char ch = getchar();
                if (ch == '\n') ch = getchar();
                if (ch == '#') map[i][j] = 1;
                if (ch == '@') { stx = i; sty = j; }
            }
        dfs(stx, sty);
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (vis[i][j]) ans++;
        printf("%d\n", ans);
    }
    return 0;
}
