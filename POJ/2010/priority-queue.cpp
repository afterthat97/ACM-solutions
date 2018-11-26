#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
#define maxc 100005
#define maxn 20005
#define ll long long
using namespace std;

pair<int, int> stu[maxc];
int n, c, f;
ll l[maxc], r[maxc];

void work_l() {
    ll fsum = 0;
    priority_queue<int, vector<int> > q;
    for (int i = 0; i < n / 2; i++) {
        q.push(stu[i].second);
        fsum += stu[i].second;
    }
    l[n / 2] = fsum;
    for (int i = n / 2; i < c - 1; i++) {
        if (q.top() > stu[i].second) {
            fsum -= q.top();
            q.pop();
            fsum += stu[i].second;
            q.push(stu[i].second);
        }
        l[i + 1] = fsum;
    }
}

void work_r() {
    ll fsum = 0;
    priority_queue<int, vector<int> > q;
    for (int i = c - 1; i >= c - n / 2; i--) {
        q.push(stu[i].second);
        fsum += stu[i].second;
    }
    r[c - n / 2 - 1] = fsum;
    for (int i = c - n / 2 - 1; i > 0; i--) {
        if (q.top() > stu[i].second) {
            fsum -= q.top();
            q.pop();
            fsum += stu[i].second;
            q.push(stu[i].second);
        }
        r[i - 1] = fsum;
    }
}

int main() {
    scanf("%d %d %d", &n, &c, &f);
    for (int i = 0; i < c; i++)
        scanf("%d %d", &stu[i].first, &stu[i].second);
    sort(stu, stu + c);
    work_l();
    work_r();
    int ans = -1;
    for (int i = n / 2; i < c - n / 2; i++)
        if (l[i] + r[i] + stu[i].second <= (ll) f)
            ans = stu[i].first;
    printf("%d\n", ans);
    return 0;
}
