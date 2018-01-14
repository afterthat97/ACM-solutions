#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <stdlib.h>
using namespace std;

char s[1005];
int len, ans;

int main() {
	gets(s);
	len = strlen(s);

	for (int i = 0; i < len; i++) {
		int j = 1;
		for (; i - j >= 0 && i + j < len; j++)
			if (s[i - j] != s[i + j]) break;
		if ((j - 1) * 2 + 1 > ans) ans = (j - 1) * 2 + 1;
	}

	for (int i = 0; i < len - 1; i++) {
		int l = i, r = i + 1, cnt = 0;
		while (s[l] == s[r]) {
			l--; r++;
			cnt += 2;
			if (l < 0 || r >= len) break;
		}
		if (cnt > ans) ans = cnt;
	}
	cout << ans << endl;
	return 0;
}
