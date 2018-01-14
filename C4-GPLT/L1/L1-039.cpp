#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

char a[105][105], s[1005];

int main() {
	int k; cin >> k;
	gets(s);
	if (s[0] == 0) gets(s);
	int len = strlen(s), cnti = 0, cntj = 100;
	for (int i = 0; i < len; i++) {
		if (cnti == k) {
			cnti = 0; cntj--;
		}
		a[cnti][cntj] = s[i];
		cnti++;
	}
	for (int i = 0; i < k; i++) {
		for (int j = cntj; j <= 100; j++) {
			if (a[i][j] == 0) a[i][j] = ' ';
			putchar(a[i][j]);
		}
		cout << endl;
	}
	return 0;
}
