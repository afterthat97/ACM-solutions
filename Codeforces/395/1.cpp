#include <iostream>
#include <stdio.h>
using namespace std;

int d[10005];
int n,m,z;

int main() {
	scanf("%d %d %d", &n, &m, &z);
	for (int i = 1; i * n <= z; i++)
		d[i * n] = 1;
	int cnt = 0;
	for (int i = 1; i * m <= z; i++)
		if (d[i * m] == 1) cnt++;
	cout << cnt << endl;
	return 0;
}
