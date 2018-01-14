#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int n, minlen;
char s1[260], s2[260];
int len1, len2, len;

int main() {
	scanf("%d %s", &n, s1);
	len1 = strlen(s1);

	int sum = len1;
	for (int idx = 1; idx < n; idx++) {
		scanf("%s", s2);
		len2 = strlen(s2);
		minlen = min(len1, len2);
		len = 0;
		for (int i = 0; i < minlen; i++)
			if (s1[i] == s2[i])
				len++;
			else
				break;
		sum += len2 - len + 1;
		strcpy(s1, s2); len1 = len2;
	}
	cout << sum;
	return 0;
}
