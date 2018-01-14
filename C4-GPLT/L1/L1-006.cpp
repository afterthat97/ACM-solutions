#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int nn; cin >> nn;
    int ans = 0, anss;
    for (int st = 2; st < 100; st++) {
        int start = st, end = st;
        if (nn % start) continue;
        int n = nn / start;
        while (start <= end) {
            if (n % (end + 1) == 0) {
                n /= end + 1;
                end++;
            } else {
                if (end - start + 1 > ans) {
                    ans = end - start + 1;
                    anss = start;
                } else if (end - start + 1 == ans && start < anss) {
                    anss = start;
                }
                n *= start;
                start++;
            }
        }
        st = start - 1;
    }
    if (ans == 0) {
        cout << 1 << endl << nn;
        return 0;
    }
    cout << ans << endl;
    for (int i = 1; i < ans; i++)
        cout << anss + i - 1 << "*";
    cout << anss + ans - 1 << endl;
    return 0;
}
