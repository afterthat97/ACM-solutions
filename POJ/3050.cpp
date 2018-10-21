#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <set>
#include <string>
using namespace std;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int map[6][6];
set<string> res;
string cnt;

void dfs(int x, int y, int k) {
    if (k == 5) {
        res.insert(cnt);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx > 4 || ny > 4) continue;
        cnt = cnt + (char(map[nx][ny] + '0'));
        dfs(nx, ny, k + 1);
        cnt.erase(cnt.size() - 1, 1);
    }    
}

int main() {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> map[i][j];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) {
            cnt = char(map[i][j] + '0');
            dfs(i, j, 0);
        }
    cout << res.size() << endl;
    return 0;
}
