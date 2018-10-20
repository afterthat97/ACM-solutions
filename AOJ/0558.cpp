#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct node {
    int x, y, steps;
};

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
int n, m, map[1005][1005], vis[1005][1005], num, stx, sty;

int bfs() {
    int tot = 0;
    for (int i = 1; i <= num; i++) {
        memset(vis, 0x3f, sizeof vis);
        vis[stx][sty] = 0;
        queue<node> q;
        q.push({ stx, sty, 0 });
        while (!q.empty()) {
            node cnt = q.front(); q.pop();
            if (map[cnt.x][cnt.y] == '0' + i) {
                tot += cnt.steps;
                stx = cnt.x; sty = cnt.y;
                break;
            }
            for (int k = 0; k < 4; k++) {
                int nx = cnt.x + dx[k];
                int ny = cnt.y + dy[k];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (map[nx][ny] == 'X' || vis[nx][ny] <= cnt.steps + 1) continue;
                vis[nx][ny] = cnt.steps + 1;
                q.push({ nx, ny, cnt.steps + 1 });
            }
        }
    }
    return tot;
}

int main() {
    scanf("%d %d %d", &n, &m, &num);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char ch = getchar();
            if (ch == '\n') ch = getchar();
            if (ch == 'S') { stx = i; sty = j; }
            map[i][j] = ch;
        }
    cout << bfs() << endl;
    return 0;
}
