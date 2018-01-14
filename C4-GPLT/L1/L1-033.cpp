#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int judge(char s[10]) {
	int cnt[10] = {}, ans = 0;
	for (int i = 0; i < 4; i++) cnt[s[i] - '0']++;
	for (int i = 0; i < 10; i++)
		if (cnt[i]) ans++;
	return ans;
}

int main() {
	int age = 0, k, year;
	cin >> year >> k;
	while (1) {
		char s[10];
		sprintf(s, "%04d", year);
		if (judge(s) == k) {
			printf("%d %04d", age, year);
			return 0;
		}
		age++; year++;
	}
	return 0;
}
