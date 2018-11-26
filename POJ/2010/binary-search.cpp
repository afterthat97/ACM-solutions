#include <iostream>
#include <stdio.h>
#include <algorithm>
#define maxc 100005
#define maxn 20005
#define ll long long
using namespace std;

struct student {
    int score, finan, id;
}stu_s[maxc], stu_f[maxc];
int n, c, f;

bool cmp_s(const student& a, const student& b) {
    return a.score < b.score;
}

bool cmp_f(const student& a, const student& b) {
    return a.finan < b.finan;
}

int main() {
    scanf("%d %d %d", &n, &c, &f);
    for (int i = 0; i < c; i++)
        scanf("%d %d", &stu_s[i].score, &stu_s[i].finan);
    sort(stu_s, stu_s + c, cmp_s);
    for (int i = 0; i < c; i++) {
        stu_s[i].id = i;
        stu_f[i] = stu_s[i];
    }
    sort(stu_f, stu_f + c, cmp_f);
    int l = 0, r = c - 1, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        int lnum = 0, rnum = 0, totf = stu_s[mid].finan;
        for (int i = 0; i < c; i++) {
            if (stu_f[i].id < mid && stu_f[i].finan + totf <= f && lnum < n / 2) {
                lnum++;
                totf += stu_f[i].finan;
            }
            if (stu_f[i].id > mid && stu_f[i].finan + totf <= f && rnum < n / 2) {
                rnum++;
                totf += stu_f[i].finan;
            }
        }
        if (lnum < n / 2 && rnum < n / 2) {
            break;
        } else if (rnum < n / 2) {
            r = mid - 1;
        } else if (lnum < n / 2) {
            l = mid + 1;
        } else {
            ans = max(ans, stu_s[mid].score);
            l = mid + 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
