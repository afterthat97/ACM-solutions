#include <iostream>
#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <functional>
#include <string>
#define pause cin.get();cin.get();
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;

string s;

int main() {
	cin >> s;
	bool succ = 1;
	char b = 'a' - 1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] <= b) continue;
		if (s[i] > b + 1) {
			succ = 0;
			break;
		}
		b = s[i];
	}
	if (succ) puts("YES");
	else puts("NO");
	pause
	return 0;
}