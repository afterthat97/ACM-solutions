#include <iostream>
#include <stdio.h>
using namespace std;

int n, x, a[10][3];

int main() {
	a[0][0] = 0; a[0][1] = 1; a[0][2] = 2;
	for (int i = 1; i < 6; i++)
		if (i & 1) {
			a[i][0] = a[i - 1][1]; a[i][1] = a[i - 1][0]; a[i][2] = a[i - 1][2];
		} else {
			a[i][0] = a[i - 1][0]; a[i][1] = a[i - 1][2]; a[i][2] = a[i - 1][1];
		}

	while (scanf("%d %d", &n, &x) == 2) cout << a[n % 6][x] << endl;
	return 0;
}
