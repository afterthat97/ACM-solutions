#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
using namespace std;

char s[105], tmp[105];

int main() {
	while (scanf("%s", s) == 1) {
		int l = 0, r = strlen(s) - 1;
		while (l <= r) {
			if (l == r) { putchar(s[l]); break; }
			if (s[l] < s[r]) {
				putchar(s[l]); l++; continue;
			} else if (s[l] > s[r]) {
				putchar(s[r]); r--; continue;
			} else {
				for (int i = 1; l + i <= r; i++)
					if (s[l + i] < s[r - i]) {
						putchar(s[l]); l++; break;
					} else if (s[l + i] > s[r - i]) {
						putchar(s[r]); r--; break;
					} else if (l + i == r) {
						putchar(s[r]); r--; break;
					}
			}
		}
		putchar('\n');
	}
	return 0;
}
