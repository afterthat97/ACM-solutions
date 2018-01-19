#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

char s[10005];
int cnt[200];

int main() {
	gets(s);
	int len = strlen(s), sum = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] >= 'a') 
			s[i] = s[i] - 'a' + 'A';
		if (s[i] == 'g' || s[i] == 'G' || s[i] == 'p'
			|| s[i] == 'P' || s[i] == 'l' || s[i] == 'L'
			|| s[i] == 't' || s[i] == 'T') {
			sum++;
			cnt[s[i]]++;
		}
	}
	while (sum--) {
		if (cnt['G']) {
			cout << "G";
			cnt['G']--;
		}
		if (cnt['P']) {
			cout << "P";
			cnt['P']--;
		}
		if (cnt['L']) {
			cout << "L";
			cnt['L']--;
		}
		if (cnt['T']) {
			cout << "T";
			cnt['T']--;
		}
	}
	return 0;
}
