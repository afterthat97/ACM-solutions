#include <iostream>
#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <functional>
#include <string>
#define pause cin.get();cin.get();
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;

int a,b, k;

int main() {
	cin >> k >> a >> b;
	/*if (a < k && b < k) {
		cout << -1;
	} else if (a < k && b == k) {
		cout << 1;
	} else if (b < k && a == k) {
		cout << 1;
	} else if (a == k && b == k) {
		cout << 2;
	} else {

	}*/
	if (a < k && b < k) {
		cout << -1;
		return 0;
	}
	if (a < k) {
		if (b % k == 0) cout << b / k;
		else cout << -1;
		return 0;
	}
	if (b < k) {
		if (a % k == 0) cout << a / k;
		else cout << -1;
		return 0;
	}
	int ans = (a / k) + (b / k);
	cout << ans;
	pause
	return 0;
}