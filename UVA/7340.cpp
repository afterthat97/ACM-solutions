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

ull dat[20000010];
int n;

void init() {
	for (uint i = 10001; i < 20000001; i++)
		for (uint j = 1; i*j < 20000001; j++)
			dat[i*j] += i;
	for (uint i = 2; i < 20000001; i++)
		dat[i] += dat[i - 1];
}

ull cnt(int x) {
	ull ans = 0;
	for (int i = 1; i <= 10000; i++)
		ans += (x / i)*i;
	return ans;
}

int main() {
	init();
	while (scanf("%d", &n) == 1 && n)
		printf("%lld\n", dat[n] - 1 + cnt(n));

	return 0;
}