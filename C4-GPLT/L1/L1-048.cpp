#include <iostream>
#include <stdio.h>
using namespace std;

int mat1[105][105], mat2[105][105], ans[105][105];

int main() {
	int x1, y1, x2, y2;
	cin >> x1 >> y1;
	for (int i = 0; i < x1; i++)
		for (int j = 0; j < y1; j++)
			cin >> mat1[i][j];
	cin >> x2 >> y2;
	for (int i = 0; i < x2; i++)
		for (int j = 0; j < y2; j++)
			cin >> mat2[i][j];
	if (y1 != x2) {
		printf("Error: %d != %d\n", y1, x2);
		return 0;
	}
	int n = x1, m = y2;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < y1; k++)
				ans[i][j] += mat1[i][k] * mat2[k][j];
	cout << n << ' ' << m << endl;
	for (int i = 0; i < n; i++) {
		cout << ans[i][0];
		for (int j = 1; j < m; j++)
			cout << ' ' << ans[i][j];
		cout << endl;
	}
	return 0;
}
