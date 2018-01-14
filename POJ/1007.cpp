#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

struct node {
	string str;
	int num;
} a[105];

bool cmp(const node& a, const node& b) {
	if (a.num == b.num)
		return a.str < b.str;
	return a.num < b.num;
}

int main() {
	int len, n;
	cin >> len >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].str;
		int tot = 0;
		for (int j = 0; j < a[i].str.length(); j++)
			for (int k = j + 1; k < a[i].str.length(); k++)
				if (a[i].str[j] > a[i].str[k]) tot++;
		a[i].num = tot;
	}
	sort(a, a + n, cmp);
	for (int i = 0; i < n; i++)
		cout << a[i].str << endl;
	return 0;
}
