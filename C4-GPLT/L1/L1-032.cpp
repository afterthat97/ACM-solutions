#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int main() {
	char *s = new char[10005];
	int n; char ch;
	cin >> n >> ch;
	gets(s);
	if (s[0] == 0) gets(s);
	int len = strlen(s);
	if (len >= n) {
		s = s + len - n;
		puts(s);
	} else {
		for (int i = 0; i < n - len; i++) putchar(ch);
		puts(s);
	}
	return 0;
}
