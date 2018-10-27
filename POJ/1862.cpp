#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n; cin >> n;
    double a[105];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for (int i = n - 1; i > 0; i--)
        a[i - 1] = 2 * sqrt(a[i - 1] * a[i]);
    printf("%.3f\n", a[0]);
    return 0;
}
