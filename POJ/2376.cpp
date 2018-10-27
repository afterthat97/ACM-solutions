#include <iostream>
#include <stdio.h>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> node;

int n, t, ans;
vector<node> a;

int main() {
    scanf("%d %d", &n, &t);
    for (int i = 0; i < n; i++) {
        int st, ed;
        scanf("%d %d", &st, &ed);
        a.push_back(node(st, ed));
    }
    sort(a.begin(), a.end());
    for (int i = 0, cnt = 0; cnt < t; ) {
        int maxx = 0;
        while (i < a.size() && a[i].first <= cnt + 1) {
            maxx = max(maxx, a[i].second);
            i++;
        }
        if (maxx == 0) {
            printf("%d\n", -1);
            return 0;
        }
        cnt = maxx;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}
