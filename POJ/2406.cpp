#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <stdlib.h>
#define maxn 1000
#define maxm 1000010
using namespace std;

int f[maxm], n;
char s[maxm];

void getf(char *p) {
	int len = strlen(p);
	memset(f, -1, sizeof f);
	for (int i = 0, j = -1; i < len;) {
		while (~j && p[i] != p[j]) j = f[j];
		i++; j++;
		f[i] = j;
	}
}

int main() {
	int idx = 0;
	while (scanf("%s", s) == 1) {
		if (s[0] == '.' && s[1] == 0) break;
		int len = strlen(s);
		getf(s);
		if (f[len] > 0 && len % (len - f[len]) == 0)
			printf("%d\n", len / (len - f[len]));
		else
			printf("1\n");
	}	

    return 0;
}
