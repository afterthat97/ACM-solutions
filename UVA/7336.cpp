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

int T, n, dat[11][2][2];

int main() {
	read(T);
	for (int idx = 0; idx < T; idx++) {
		read(n);
		memset(dat, 0, sizeof(dat));
		for (int i = 0; i < n; i++) {
			int diff, leak;
			char ch;
			scanf("%d %d %c", &diff, &leak, &ch);
			if (ch == 'c') ch = 1;
			else ch = 0;
			dat[diff][leak][ch]++;
		}
		ll ans = 0;
		for (int i = 1; i < 10; i++) {
			int a = dat[i][0][0];
			int b = 0;
			for (int j = i + 1; j <= 10; j++)
				b += dat[j][1][1];
			ans += a*b;
		}
		cout << ans << endl;
	}
	return 0;
}