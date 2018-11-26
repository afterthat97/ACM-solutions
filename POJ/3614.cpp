#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#define maxn 3000
#define maxm 3000
using namespace std;

priority_queue<int, vector<int>, greater<int> > q;
pair<int, int> cow[maxn], lotion[maxm];
int n, m;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &cow[i].first, &cow[i].second);
    for (int i = 0; i < m; i++)
        scanf("%d %d", &lotion[i].first, &lotion[i].second);
    sort(cow, cow + n);
    sort(lotion, lotion + m);
    int ans = 0;
    for (int i = 0, j = 0; j < m; j++) {
        while (i < n && cow[i].first <= lotion[j].first)
            q.push(cow[i++].second);
        while (!q.empty() && lotion[j].second) {
            if (q.top() >= lotion[j].first) {
                lotion[j].second--;
                ans++;
            }
            q.pop();
        }
    }
    printf("%d\n", ans);
    return 0;
}
