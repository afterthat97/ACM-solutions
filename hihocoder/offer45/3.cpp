#include <iostream>
#include <stdio.h>
#include <cstring>
#define maxl 100005
#define fst first
#define snd second
using namespace std;

char str1[maxl], str2[maxl];
pair<char, int> idx1[maxl], idx2[maxl];

int solve() {
	int len = strlen(str1), num1 = 0, num2 = 0, ans = 0;
	if (strlen(str2) != len) return -1;
	for (int i = 0; i < len; i++) {
		if (str1[i] != '_') idx1[num1++] = pair<char, int>(str1[i], i);
		if (str2[i] != '_') idx2[num2++] = pair<char, int>(str2[i], i);
	}
	if (num1 != num2) return -1;
	for (int i = 0; i < num1; i++) {
		if (idx1[i].fst != idx2[i].fst) return -1;
		if (idx1[i].fst == 'L' && idx2[i].snd > idx1[i].snd) return -1;
		if (idx1[i].fst == 'R' && idx2[i].snd < idx1[i].snd) return -1;
		ans += abs(idx1[i].snd - idx2[i].snd);
	}
	return ans;
}

int main() {
	scanf("%s %s", str1, str2);
	cout << solve() << endl;
	return 0;
}
