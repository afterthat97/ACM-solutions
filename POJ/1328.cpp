#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef pair<double, double> node;
vector<node> a;
int n, d, T;

double getdx(int y) {
    if (y > d) return 0;
    return sqrt(d * d - y * y);
}

bool cmp(const node& a, const node& b) {
    return a.second < b.second;
}

int main() {
    while (scanf("%d %d", &n, &d) == 2 && n) {
        T++;
        a.clear();
        int maxy = 0;
        for (int i = 0; i < n; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            maxy = max(maxy, y);
            a.push_back(node(x - getdx(y), x + getdx(y)));
        }
        if (maxy > d) {
            printf("Case %d: %d\n", T, -1);
            continue;
        }
        sort(a.begin(), a.end(), cmp);
        int ans = 1;
        double r = a[0].second;
        for (int i = 1; i < a.size(); i++) {
            if (a[i].first < r || fabs(a[i].first - r) < 1e-8) continue;
            r = a[i].second;
            ans++;
        }
        printf("Case %d: %d\n", T, ans);
    }
    return 0;
}
