#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		int minn = 0, maxn = 0, minv = 1, maxv = 1;
		int minset[100], maxset[100];
		if (n & 1) {
			for (int i = 1; i < n; i += 2) {
				printf("? %d %d\n", i, i + 1);
				fflush(stdout);
				char ch; cin >> ch;
				if (ch == '>') {
					minset[minn++] = i + 1;
					maxset[maxn++] = i;
				} else {
					minset[minn++] = i;
					maxset[maxn++] = i + 1;
				}
			}
			minset[minn++] = n;
			maxset[maxn++] = n;
			minv = minset[0]; maxv = maxset[0];
			for (int i = 1; i < minn; i++) {
				printf("? %d %d\n", minset[i], minv);
				fflush(stdout);
				char ch; cin >> ch;
				if (ch == '<') minv = minset[i];
			}
			for (int i = 1; i < maxn; i++) {
				printf("? %d %d\n", maxset[i], maxv);
				fflush(stdout);
				char ch; cin >> ch;
				if (ch == '>') maxv = maxset[i];
			}
			printf("! %d %d\n", minv, maxv);
			fflush(stdout);
		} else {
			for (int i = 1; i < n; i += 2) {
				printf("? %d %d\n", i, i + 1);
				fflush(stdout);
				char ch; cin >> ch;
				if (ch == '>') {
					minset[minn++] = i + 1;
					maxset[maxn++] = i;
				} else {
					minset[minn++] = i;
					maxset[maxn++] = i + 1;
				}
			}
			minv = minset[0]; maxv = maxset[0];
			for (int i = 1; i < minn; i++) {
				printf("? %d %d\n", minset[i], minv);
				fflush(stdout);
				char ch; cin >> ch;
				if (ch == '<') minv = minset[i];
			}
			for (int i = 1; i < maxn; i++) {
				printf("? %d %d\n", maxset[i], maxv);
				fflush(stdout);
				char ch; cin >> ch;
				if (ch == '>') maxv = maxset[i];
			}
			printf("! %d %d\n", minv, maxv);
			fflush(stdout);
		}
	}
	return 0;
}
