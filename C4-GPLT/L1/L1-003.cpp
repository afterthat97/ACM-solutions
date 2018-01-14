#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

char s[1005];
int cnt[15];

int main() {
	gets(s);
	int len = strlen(s);
	for (int i = 0; i < len; i++)
		cnt[s[i] - '0']++;
	for (int i = 0; i < 10; i++)
		if (cnt[i])
			cout << i << ':' << cnt[i] << endl;
	return 0;
}
