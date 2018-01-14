#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;

ll n, l, r;
ll a[100005], p[100005], pos[100005], b[100005];

int main() {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)
		scanf("%I64d", &a[i]);
	for (int i = 0; i < n; i++) {
		scanf("%I64d", &p[i]);
		pos[p[i]] = i;
	}
	b[pos[1]] = l;
	ll bef = b[pos[1]] - a[pos[1]];
	for (int i = 2; i <= n; i++) {
		b[pos[i]] = a[pos[i]] + bef + 1;
		b[pos[i]] = max(l, b[pos[i]]);
		bef = b[pos[i]] - a[pos[i]];
		if (b[pos[i]] > r) {
			cout << -1 << endl;
			return 0;
		}
	}
	cout << b[0];
	for (int i = 1; i < n; i++)
		printf(" %I64d", b[i]);
	return 0;
}