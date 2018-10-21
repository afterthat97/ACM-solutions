#include <iostream>
#include <stdio.h>
using namespace std;

int a[15], n;

int main() {
    int T; cin >> T; getchar();
    while (T--) {
        n = 0;
        while (true) {
            char ch = getchar();
            if (ch == ' ') continue;
            if (ch == '\n') break;
            a[n++] = ch - '0';
        }
        if (n == 2)
            cout << a[1] - a[0] << endl;
        else if (n % 2) {
            int part1 = (a[0] == 0 ? a[1] * 10 + a[0] : a[0] * 10 + a[1]);
            for (int j = 2, cnt = 0; j < n && cnt < n / 2 - 1; j++) {
                part1 = part1 * 10 + a[j];
                cnt++;
            }
            int part2 = a[n - 1];
            for (int j = n - 2, cnt = 0; j >= 0 && cnt < n / 2 - 1; j--) {
                part2 = part2 * 10 + a[j];
                cnt++;
            }
            cout << part1 - part2 << endl;
        } else {
            int ans = 0x3f3f3f3f;
            for (int i = 0; i < n - 1; i++) {
                if (a[i] == 0) continue;
                int part1 = a[i + 1];
                for (int j = 0, cnt = 0; j < n && cnt < n / 2 - 1; j++)
                    if (j != i && j != i + 1) {
                        part1 = part1 * 10 + a[j];
                        cnt++;
                    }
                int part2 = a[i];
                for (int j = n - 1, cnt = 0; j >= 0 && cnt < n / 2 - 1; j--)
                    if (j != i && j != i + 1) {
                        part2 = part2 * 10 + a[j];
                        cnt++;
                    }
                ans = min(ans, part1 - part2);
            }
            cout << ans << endl;
        }
    }
    return 0;
}
