#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <ctime>
#include <stdlib.h>
#define maxn 200005
using namespace std;

long long a[maxn];
int idx[maxn], p[maxn];
int n, m;

int get(int l, int r, long long pos) {
    while (l < r - 1) {
        int mid = (l + r) >> 1;
        if (a[mid] == pos) return mid;
        if (a[mid] > pos) r = mid;
        else l = mid;
    }
    if (a[r] > pos) return l;
    return r;
}

bool cmp(int x, int y) {
    return a[x] < a[y];
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        idx[i] = i;
    }
    a[n + 1] = 0x7fffffffff;
    a[0] = -a[n + 1];
    sort(idx + 1, idx + n + 1, cmp);
    sort(a, a + n + 1);
    for(int i = 1; i <= n; ++i){
        p[idx[i]] = i;
    }
    for (int i = 0; i < m; i++) {
        int id; long long len;
        scanf("%d %lld", &id, &len);
        id = p[id];
        int pre = id, start = id;
        while (1) {
            start = pre;
            if (len == 0) break;
            if (len < a[id + 1] - a[id] && len < a[id] - a[id - 1])
                break;
            id = get(pre, n + 1, a[pre] + len);
            len -= a[id] - a[pre];
            pre = id;
            id = get(0, pre, a[pre] - len);
            if (a[pre] - a[id] != len) id++;
            len -= a[pre] - a[id];
            if (start == id) {
                long long dl = (a[pre] - a[start]) << 1;
                if (dl) len %= dl;
            }
            pre = id;
        }
        printf("%d\n", idx[id]);
    }
    
    
    return 0;
}
