#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;

ll cnt, minn = 0x3f3f3f3f, all;

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &cnt);
		all += cnt;
		if (all < minn) minn = all;
	}
	if (minn > 0) minn = 0;
	cout << -minn << endl;
	return 0;
}