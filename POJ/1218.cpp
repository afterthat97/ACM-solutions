#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <stdio.h>
#define read(i) scanf("%d", &i);
using namespace std;

int num, n;
bool cell[101];

int main() {
	read(num);
	for (int i = 0; i < num; i++) {
		memset(cell, 0, sizeof(cell));
		read(n);
		for (int j = 2; j <= n; j++) {
			int k = 0;
			while (k <= n) {
				cell[k] = !cell[k];
				k += j;
			}
		}
		int ans = 0;
		for (int j = 1; j <= n; j++)
			if (!cell[j])
				ans++;
		printf("%d\n", ans);
	}
	return 0;
}