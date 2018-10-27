#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#define maxn 50005
#define maxt 1000005
using namespace std;

struct node {
    int x, y, id;
};

typedef pair<int, int> P;
vector<node> a;
int axis[maxt], ans[maxn], n;

int getMinStalls() {
    memset(axis, 0, sizeof axis);
    for (int i = 0; i < a.size(); i++) {
        axis[a[i].x]++;
        axis[a[i].y + 1]--;
    }
    int maxx = 0, tot = 0;
    for (int i = 0; i < maxt; i++) {
        tot += axis[i];
        maxx = max(maxx, tot);
    }
    return maxx;
}

bool cmp(const node& a, const node& b) {
    return a.x < b.x;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        a.push_back(node{ x, y, i });
    }
    sort(a.begin(), a.end(), cmp);

    int num = getMinStalls();
    printf("%d\n", num);
    
    priority_queue<P, vector<P>, greater<P> > q;
    for (int i = 0; i < num; i++) q.push(P(0, i + 1));
    for (int i = 0; i < n; i++) {
        P cnt = q.top(); q.pop();
        cnt.first = a[i].y;
        q.push(cnt);
        ans[a[i].id] = cnt.second;
    }
    for (int i = 0; i < n; i++)
        printf("%d\n", ans[i]);
    return 0;
}
