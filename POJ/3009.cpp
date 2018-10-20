#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
int n, m, map[25][25], vis[25][25], stx, sty, edx, edy, ans;

void dfs(int x, int y, int steps) {
    if (steps > 10) return;
    for (int k = 0; k < 4; k++) {
        int cx = x, cy = y, nx = cx + dx[k], ny = cy + dy[k];
        if (map[nx][ny] == 1) continue;
        while (true) {
            if (cx == edx && cy == edy) { ans = min(ans, steps + 1); break; }
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) break;
            if (map[nx][ny] == 1) {
                map[nx][ny] = 0;
                dfs(cx, cy, steps + 1);
                map[nx][ny] = 1;
                break;
            }
            cx = nx; cy = ny; nx += dx[k]; ny += dy[k];
        }
    }
}

int main() {
    while (scanf("%d %d", &m, &n) == 2 && n && m) {
        memset(map, 0, sizeof map);
        memset(vis, 0x3f, sizeof vis);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                scanf("%d", &map[i][j]);
                if (map[i][j] == 2) { stx = i; sty = j; }
                if (map[i][j] == 3) { edx = i; edy = j; }
            }
        ans = 11;
        dfs(stx, sty, 0);
        printf("%d\n", ans > 10 ? -1 : ans);
    }
    return 0;
}
