#include <iostream>
#include <stdio.h>
using namespace std;

int a, b, c;

int main() {
	while (scanf("%d %d %d", &a, &b, &c) == 3) {
		int ans = a;
		if (b / 2 < ans) ans = b / 2;
		if (c / 4 < ans) ans = c / 4;
		cout << ans * 7 << endl;
	}
	return 0;
}
