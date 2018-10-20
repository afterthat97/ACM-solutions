#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int a = 0, b = 0, succ = 1;
        for (int i = 0; i < 10; i++) {
            int n; scanf("%d", &n);
            if (a > b) {
                if (n > a) a = n;
                else if (n > b) b = n;
                else succ = 0;
            } else {
                if (n > b) b = n;
                else if (n > a) a = n;
                else succ = 0;
            }
        }
        puts(succ ? "YES" : "NO");
    }
    return 0;
}
