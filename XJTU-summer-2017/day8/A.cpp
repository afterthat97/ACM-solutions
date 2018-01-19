#include <iostream>
#include <stdio.h>
#include <cstring>
#define maxn 1000005
using namespace std;

int f[maxn];

void getf(char *p) {
	int len = strlen(p);
	memset(f, -1, sizeof f);
	for (int i = 0, j = -1; i < len;) {
		while (~j && p[i] != p[j]) j = f[j];
		i++; j++;
		f[i] = p[i] == p[j] ? f[j] : j;
	}
}

int kmp(char *t, char *p) {
	int len = strlen(t), lenp = strlen(p);
	getf(p);
	for (int i = 0, j = 0; i < len;) {
		while (~j && t[i] != p[j]) j = f[j];
		i++; j++;
		if (j == lenp) return i - j;
	}
	return -1;
}

char t[maxn], p[maxn];

int main() {
	while (scanf("%s %s", t, p) == 2) {
		int len = strlen(p), ans = 0;
		for (int i = 0; i < len; i++)
			p[i] = p[i] - 'A' + 'a';
		char* st = t;
		while (1) {
			int pos = kmp(st, p);
			if (pos != -1) {
				ans++; st += pos + len;
			} else break;
		}
		cout << ans << endl;
	}
	return 0;
}
