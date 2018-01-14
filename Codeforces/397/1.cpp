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

int n;
string home;
string tmp;

int main() {
	cin >> n >> home;
	int go = 0, back = 0;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp[0] == home[0] && tmp[1] == home[1] && tmp[2] == home[2]) {
			go++;
		} else {
			back++;
		}
	}
	if (go > back) cout << "contest";
	else cout << "home";
	pause
	return 0;
}