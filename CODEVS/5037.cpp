#include <stdio.h>
#include <cmath>

int bkt[450][201005], addv[450], size, kk, a[200005], n, m;

void add(int l, int r, int v) {
    int idx1 = l / size, idx2 = r / size;
    if (idx1 == idx2) {
        for (int k = l; k <= r; ++k) {
            bkt[idx1][a[k]]--;
            a[k] = (a[k] + v) % kk;
            bkt[idx1][a[k]]++;
        }
        return;
    }
    for (int k = idx1 + 1; k < idx2; ++k)
        addv[k] = (addv[k] + v) % kk;
    for (int k = l; k < (idx1 + 1) * size; ++k) {
        bkt[idx1][a[k]]--;
        a[k] = (a[k] + v) % kk;
        bkt[idx1][a[k]]++;
    }
    for (int k = idx2 * size; k <= r; ++k) {
        bkt[idx2][a[k]]--;
        a[k] = (a[k] + v) % kk;
        bkt[idx2][a[k]]++;
    }
}

int query(int l, int r) {
    int idx1 = l / size, idx2 = r / size, ans = 0;
    if (idx1 == idx2) {
        for (int k = l; k <= r; ++k)
            if ((a[k] + addv[idx1]) % kk == 0) ++ans;
        return ans;
    }
    for (int k = idx1 + 1; k < idx2; ++k)
        ans += bkt[k][addv[k] ? kk - addv[k] : 0];
    for (int k = l; k < (idx1 + 1) * size; ++k)
        if ((a[k] + addv[idx1]) % kk == 0) ++ans;
    for (int k = idx2 * size; k <= r; ++k)
        if ((a[k] + addv[idx2]) % kk == 0) ++ans;
    return ans;
}

int main() {
    scanf("%d %d %d", &n, &m, &kk);
    size = floor(sqrt(n));
    for (int i = 0; i < n; ++i) {//i / size; i % size
        scanf("%d", &a[i]);
        a[i] %= kk;
        bkt[i / size][a[i]]++;
    }
    for (int i = 0; i < m; ++i) {
        char opt[10]; int l, r, v;
        scanf("%s", opt);
        if (opt[0] == 'a') {
            scanf("%d %d %d", &l, &r, &v);
            add(l - 1, r - 1, v);
        } else {
            scanf("%d %d", &l, &r);
            printf("%d\n", query(l - 1, r - 1));
        }
    }
    return 0;
}