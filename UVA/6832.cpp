#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <vector>
#include <ctime>
#include <sstream>
#include <deque>
#include <functional>
#include <iterator>
#include <list>
#include <memory>
#include <numeric>
#include <utility>

#define INF 999999999
#define uint unsigned int
#define uchar unsigned char
#define ll long long
#define ull unsigned long long
#define pause cin.get();cin.get();
#define read(i) scanf("%d", &i);
#define ln printf("\n");
using namespace std;

int n, m;
int raw[16], tar0[16], tar1[16], temp[16], tar[16];

int work() {
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (temp[i] != tar[i]) {
			bool find = 0;
			for (int j = i + 1; j <= n; j++)
				if (temp[j] == tar[i]) {
					temp[j] = !temp[j];
					temp[i] = !temp[i];
					ans += j - i;
					find = 1;
					break;
				}
			if (!find) return INF;
		}
	}
	return ans;
}

int main() {
	while (scanf("%d %d", &n, &m) == 2) {
		for (int i = 1; i <= n; i++)
			scanf("%d", &raw[i]);
		int cnt = 1;
		bool num = 0;
		for (int i = 0; i < m; i++) {
			int x;
			scanf("%d", &x);
			for (int j = cnt; j < cnt + x; j++) {
				tar0[j] = num;
				tar1[j] = !num;
			}
			num = !num;
			cnt += x;
		}

		for (int i = 1; i <= n; i++) {
			temp[i] = raw[i];
			tar[i] = tar0[i];
		}
		int ans0 = work();
		for (int i = 1; i <= n; i++) {
			temp[i] = raw[i];
			tar[i] = tar1[i];
		}
		int ans1 = work();
		printf("%d\n", ans1 > ans0 ? ans0 : ans1);
	}
	return 0;
}