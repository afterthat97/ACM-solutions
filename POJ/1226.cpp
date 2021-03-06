#include <iostream>
#include <stdio.h>
#include <cstring>
#define maxn 105
using namespace std;
 
int f[maxn];
char s[maxn][maxn], sub[maxn], inv[maxn];
 
void getf(char *p) {
    int len = strlen(p);
    memset(f, -1, sizeof f);
    for (int i = 0, j = -1; i < len;) {
        while (~j && p[i] != p[j]) j = f[j];
        i++; j++;
        f[i] = p[i] == p[j] ? f[j] : j;
    }
}
 
int kmp(char *t, char *p) {
    int len = strlen(t), lenp = strlen(p);
    getf(p);
    for (int i = 0, j = 0; i < len;) {
        while (~j && t[i] != p[j]) j = f[j];
        i++; j++;
        if (j == lenp) return i - j + 1;
    }
    return -1;
}
 
int main() {
    int T; cin >> T;
    for (int idx = 0; idx < T; idx++) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) 
            scanf("%s", s[i]);
        int len = strlen(s[0]), ans = 0;
        for (int i = 0; i < len; i++)
            for (int j = i + 1; j <= len; j++) {//[i, j)
                for (int k = i; k < j; k++)
                    inv[j - k - 1] = sub[k - i] = s[0][k];
                inv[j - i] = sub[j - i] = 0;
                bool succ = 1;
                for (int k = 1; k < n; k++)
                    if (!(~kmp(s[k], sub) || ~kmp(s[k], inv))) {
                        succ = 0;
                        break;
                    }
                if (succ && strlen(sub) > ans) ans = strlen(sub);
            }
        printf("%d\n", ans);
    }
    return 0;
}
