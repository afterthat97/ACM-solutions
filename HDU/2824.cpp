#include <iostream>
#include <stdio.h>
#include <cstring>
#define maxn 3000005
using namespace std;

bool notp[maxn];
int pnum, p[maxn];
long long phi[maxn];

void sieve(int n) {
    memset(notp, 0, sizeof notp); pnum = 0;
    for (int i = 2; i < n; i++) {
        if (!notp[i]) {
            p[pnum++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; j < pnum && i * p[j] < n; j++) {
            notp[i * p[j]] = 1;
            phi[i * p[j]] = phi[i] * (p[j] - 1);
            if (i % p[j] == 0) {
                phi[i * p[j]] = phi[i] * p[j];
                break;
            }
        }
    }
}

int main() {
    sieve(3000000);
    for (int i = 2; i < 3000000; i++)
        phi[i] += phi[i - 1];
    int a, b;
    while (scanf("%d %d", &a, &b) == 2)
        printf("%lld\n", phi[b] - phi[a - 1]);
    return 0;
}
