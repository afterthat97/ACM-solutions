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
	while (scanf("%d", &n) == 1 && n) {
		scanf("%s", s);
		int len = strlen(s);
		getf(s);
		printf("Test case #%d\n", ++idx);
		for(int i = 2; i <= len; i++)
			if (f[i] > 0 && i % (i - f[i]) == 0)
				printf("%d %d\n", i, i / (i - f[i]));
		printf("\n");
	}	

    return 0;
}
