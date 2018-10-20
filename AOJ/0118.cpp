#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { 1, 0, -1, 0 };
int n, m, map[105][105], vis[105][105];

void dfs(int x, int y, char ch) {
    if (x < 0 || y < 0 || x >= n || y >= m) return;
    if (vis[x][y] || map[x][y] != ch) return;
    vis[x][y] = true;
    for (int k = 0; k < 4; k++)
        dfs(x + dx[k], y + dy[k], ch);
}

int main() {
    while (scanf("%d %d", &n, &m) == 2 && n && m) {
        memset(map, 0, sizeof map);
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                char ch = getchar();
                if (ch == '\n') ch = getchar();
                map[i][j] = ch;
            }
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!vis[i][j]) {
                    dfs(i, j, map[i][j]);
                    ans++;
                }
        printf("%d\n", ans);
    }
    return 0;
}
