#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
string s[1005];

bool cmp1(const string& a, const string& b) {
	string ans1 = a + b;
	string ans2 = b + a;
	if (ans1 > ans2) return 1; else return 0;
}

int main() {
	while (scanf("%d", &n) == 1) {
		for (int i = 0; i < n; i++) cin >> s[i];
		sort(s, s + n, cmp1);
		for (int i = 0; i < n; i++) cout << s[i];
		cout << endl;
	}
	return 0;
}
