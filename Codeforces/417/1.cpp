#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int a[4][4];

int main() {
	for (int i = 0; i < 4; i++) 
		for (int j = 0; j < 4; j++)
			cin >> a[i][j];
	for (int i = 0; i < 4; i++)
		if (a[i][3] == 1) {
			if (a[i][0] + a[i][1] + a[i][2]) {
				puts("YES"); return 0;
			}
			if (a[(i + 1) % 4][0] == 1
			 || a[(i + 2) % 4][1] == 1
			 || a[(i + 3) % 4][2] == 1) {
				puts("YES");
				return 0;
			}
		}
	puts("NO");
	return 0;
}
