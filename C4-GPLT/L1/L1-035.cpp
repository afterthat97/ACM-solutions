#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

char s[20], a1[20], a2[20];

int main() {
	int cnt = 0;
	while (scanf("%s", s) == 1) {
		if (s[0] == '.') break;
		cnt++;
		if (cnt == 2) strcpy(a1, s);
		if (cnt == 14) strcpy(a2, s);
	}
	if (a1[0] && a2[0])
		printf("%s and %s are inviting you to dinner...", a1, a2);
	else if (a1[0])
		printf("%s is the only one for you...", a1);
	else printf("Momo... No one is for you ...");
	return 0;
}
