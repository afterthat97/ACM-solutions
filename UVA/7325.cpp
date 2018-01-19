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

char s[500010];
int belong[500010];
int blen[500010];
int a, b, len, num;

int main() {
	while (gets(s) != NULL) {
		memset(belong, 0, sizeof(belong));
		memset(blen, 0, sizeof(blen));
		scanf("%d %d\n", &a, &b);
		len = strlen(s);
		belong[0] = 0;
		blen[0] = 1;
		for (int i = 1; i < len; i++)
			if (s[i] != ' ') {
				if (s[i - 1] != ' ')
					belong[i] = belong[i - 1];
				else
					belong[i] = i;
				blen[belong[i]]++;
			}

		for (int siz = a; siz <= b; siz++) {
			int ans = blen[0];
			int pos = 0;
			while (1) {
				pos += siz - 1;
				if (pos >= len - 1) break;
				if (s[pos] == ' ') {
					pos++;
					ans += blen[pos] + 1;
				} else {
					if (s[pos + 1] == ' ') {
						pos += 2;
						ans += blen[pos] + 1;
					} else {
						pos = belong[pos];
						ans += blen[pos] + 1;
					}
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}