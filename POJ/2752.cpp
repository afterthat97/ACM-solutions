#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <stdlib.h>
#define maxm 1000010
using namespace std;

int f[maxm], n, ans[maxm];
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
		int len = strlen(s);
		getf(s);
		int p = len, cnt = 0;
		while (p > 0) {
			ans[++cnt] = p;
			p = f[p];
		}
		printf("%d", ans[cnt]);
		for (int i = cnt - 1; i; i--)
			printf(" %d", ans[i]);
		printf("\n");
	}	

    return 0;
}
