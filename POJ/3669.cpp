#include <iostream>
#include <stdio.h>
#include <cstring>
#include <queue>
#define inf 0x3f3f3f3f
using namespace std;

struct node {
    int x, y, steps;
};

const int n = 500;
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
int map[505][505], vis[505][505];

int bfs() {
    queue<node> q;
    q.push({ 0, 0, 0 });
    vis[0][0] = true;
    while (!q.empty()) {
        node cnt = q.front(); q.pop();
        if (map[cnt.x][cnt.y] <= cnt.steps) continue;
        if (map[cnt.x][cnt.y] == inf) return cnt.steps;
        for (int k = 0; k < 4; k++) {
            int nx = cnt.x + dx[k], ny = cnt.y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (vis[nx][ny]) continue;
            vis[nx][ny] = true;
            q.push({ nx, ny, cnt.steps + 1 });
        }
    }
    return -1;
}

int main() {
    memset(vis, 0, sizeof vis);
    memset(map, inf, sizeof map);
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y, t;
        scanf("%d %d %d", &x, &y, &t);
        map[x][y] = min(map[x][y], t);
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            map[nx][ny] = min(map[nx][ny], t);
        }
    }
    cout << bfs() << endl;
    return 0;
}
