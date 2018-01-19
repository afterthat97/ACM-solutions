#include <stdio.h>
#include <iostream>
using namespace std;
int main() {
	int n, odd = 0; cin >> n;
	for (int i = 0; i < n; i++) {
		int m; cin >> m;
		if (m & 1) odd++;
	}
	cout << odd << ' ' << n - odd << endl;
	return 0;
}
