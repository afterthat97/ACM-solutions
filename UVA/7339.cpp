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

char s[100005];
int sum[26];

int main() {
	int T;
	scanf("%d\n", &T);
	for (int idx = 1; idx <= T; idx++) {
		gets(s);
		int len = strlen(s);
		memset(sum, 0, sizeof(sum));
		for (int i = 0; i < len; i++)
			sum[s[i] - 'a']++;
		sort(sum, sum + 26);
		printf("Case %d: %d\n", idx, sum[0]);
	}
	return 0;
}