#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
#define read(i) scanf("%d", &i);
using namespace std;

struct cow {
	int min_SPF, max_SPF;
};

struct mdc {
	int num, SPF;
};

int n, m;
cow c[2510];
mdc s[2510];
priority_queue<int, vector<int>, greater<int> > q;

bool cmp_cow(const cow&a, const cow&b) {
	if (a.min_SPF < b.min_SPF)
		return true;
	else
		return false;
}

bool cmp_mdc(const mdc&a, const mdc&b) {
	if (a.SPF < b.SPF)
		return true;
	else
		return false;
}

int main() {
	read(n)read(m);
	for (int i = 0; i < n; i++) {
		read(c[i].min_SPF);
		read(c[i].max_SPF);
	}
	for (int i = 0; i < m; i++) {
		read(s[i].SPF);
		read(s[i].num);
	}

	sort(c, c + n, cmp_cow);
	sort(s, s + m, cmp_mdc);

	int j = 0, ans = 0;
	for (int i = 0; i < m; i++) {//the ith SPF
		while (j < n && c[j].min_SPF <= s[i].SPF) {
			q.push(c[j].max_SPF);
			j++;
		}
		while (!q.empty() && s[i].num > 0) {
			if (q.top() >= s[i].SPF) {
				s[i].num--;
				ans++;
			}
			q.pop();
		}
	}
	cout << ans << endl;
	return 0;
}
