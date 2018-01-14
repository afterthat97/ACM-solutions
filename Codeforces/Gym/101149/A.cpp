#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int t; scanf("%d", &t);
		ans = max(ans, t);
	}
	cout << ans << endl;
	return 0;
}
