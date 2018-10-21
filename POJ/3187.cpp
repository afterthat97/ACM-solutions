#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int nums[15], w[15], n, sum;

int C(int n, int m) {
    int ans = 1;
    for (int i = 0; i < m; i++)
        ans = ans * (n - i);
    for (int i = 0; i < m; i++)
        ans = ans / (i + 1);
    return ans;
}

int main() {
    cin >> n >> sum;
    for (int i = 0; i < n; i++)
        nums[i] = i + 1;
    for (int i = 0; i < n; i++)
        w[i] = C(n - 1, i);
    do {
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans += w[i] * nums[i];
        if (ans == sum) {
            for (int i = 0; i < n - 1; i++)
                cout << nums[i] << ' ';
            cout << nums[n - 1] << endl;
            return 0;
        }
    } while (next_permutation(nums, nums + n));
    return 0;
}
