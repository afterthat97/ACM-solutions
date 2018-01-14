#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
using namespace std;

struct str {
	int digit;
	int low;
	int other;
	char s[100];
};

str a[100];
int n, len;
bool d, l, o;
bool used[100];

int main() {
	cin >> n >> len;
	for (int i = 0; i < n; i++) {
		a[i].digit = 99999;
		a[i].low = 99999;
		a[i].other = 99999;
		for (int j = 1; j <= len; j++) {
			cin >> a[i].s[j];
			if (a[i].s[j] >= '0' && a[i].s[j] <= '9') {
				a[i].digit = min(j - 1, a[i].digit);
				a[i].digit = min(len - j + 1, a[i].digit);
			}
			if (a[i].s[j] >= 'a' && a[i].s[j] <= 'z') {
				a[i].low = min(j - 1, a[i].low);
				a[i].low = min(len - j + 1, a[i].low);
			}
			if (a[i].s[j] == '*' || a[i].s[j] == '#' || a[i].s[j] == '&') {
				a[i].other = min(j - 1, a[i].other);
				a[i].other = min(len - j + 1, a[i].other);
			}
		}
	}
	int ans = 99999;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				if (i != k && i != j && j != k) 
					if (a[i].digit != 99999 && a[j].low != 99999 && a[k].other != 99999) {
						if (a[i].digit + a[j].low + a[k].other < ans)
							ans = a[i].digit + a[j].low + a[k].other;
				}
	cout << ans << endl;
	return 0;
}