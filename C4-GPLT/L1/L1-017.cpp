#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

int main() {
	char *s = new char[100];
	cin >> s;
	int len = strlen(s);
	double ans = 1;
	if (s[0] == '-') {
		ans *= 1.5;
		s = s + 1;
		len--;
	}
	double cnt = 0;
	for (int i = 0; i < len; i++)
		if (s[i] == '2') cnt++;
	if (!(s[len - 1] & 1)) ans *= 2;
	ans *= (cnt / len);
	printf("%.2f%%\n", ans * 100);
	return 0;
}
