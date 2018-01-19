#include <iostream>
#include <stdio.h>
#define ll long long
#define MAXN 100005
using namespace std;

bool judge(ll x) {
	for (ll i = 2; i * i <= x; i++)
    if (x % i == 0) return 0;
	return (x != 1) && (x != 0);
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		ll m; cin >> m;
		if (judge(m)) puts("Yes"); else puts("No");
	}
	return 0;
}
