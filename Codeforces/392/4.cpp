#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;

ll dp[100][2];
ll n;//base
string k;

ll pow(ll a, ll x) {
    ll ans = 1;
    for (ll i = 1; i <= x; i++)
        ans = ans * a;
    return ans;
}

int main() {
    string ns;
    cin >> ns >> k;
    n = atoi(ns.c_str());
    dp[k.size()][1] = -1;
    dp[k.size() - 1][0] = k[k.size() - 1] - '0';
    dp[k.size() - 1][1] = 0;
    for (int i = k.size() - 2; i >= 0; i--) {
        ll minn = 0x7fffffffffffffff, minj = -1;
        for (int j = 1; j <= k.size() - i; j++) {
            string sub = k.substr(i, j);
            if (sub.size() > ns.size()) break;
            if (sub.size() == ns.size() && sub >= ns) break;
            
            ll got = atoi(sub.c_str());
            if (got * pow(n, dp[i + j][1] + 1) + dp[i + j][0] < minn) {
                minn = got * pow(n, dp[i + j][1] + 1) + dp[i + j][0];
                //cout << minn << endl;
                minj = dp[i + j][1] + 1;
            }
        }
        dp[i][0] = minn;
        dp[i][1] = minj;
    }
    cout << dp[0][0] << endl;
    return 0;
}
