#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int l[3][15], r[3][15], stat[3], num[3];

bool check(int idx, int w) {
	for (int i = 0; i < 3; i++) {
		int lsum = 0, rsum = 0;
		for (int j = 0; j < num[i]; j++) {
			if (l[i][j] == idx) lsum += w;
			if (r[i][j] == idx) rsum += w;
		}
		if (lsum - rsum != stat[i]) return 0;
	}
	return 1;
}

int main() {
	int T; cin >> T;
	while (T--) {
		char s1[10], s2[10], info[10];
		for (int i = 0; i < 3; i++) {
			cin >> s1 >> s2 >> info;
			num[i] = strlen(s1);
			for (int j = 0; j < num[i]; j++) {
				l[i][j] = s1[j] - 'A';
				r[i][j] = s2[j] - 'A';
			}
			if (info[0] == 'e') { // even
				stat[i] = 0;
			} else if (info[0] == 'u') { // up
				stat[i] = 1;
			} else {
				stat[i] = -1;
			}
		}
		for (int i = 0; i < 12; i++)
			if (check(i, 1))
				printf("%c is the counterfeit coin and it is heavy.\n", i + 'A');
			else if (check(i, -1))
				printf("%c is the counterfeit coin and it is light.\n", i + 'A');
	}
	return 0;
}
