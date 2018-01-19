#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string dic[601], s;
int n, len, dp[303];

bool match(int pos, int &del) {//del:删去的最小字符数 pos：从pos往前的子串
	bool find = false;
	del = 999;
	for (int i = 0; i < n; i++) {
		int dlen = dic[i].size(), p = pos, j;
		if (dic[i][dlen - 1] != s[p]) continue;
		for (j = dlen - 1; j >= 0 && p >= 0;)
			if (dic[i][j] == s[p])
				p--, j--;
			else
				p--;

		if (j == -1) {
			find = true;
			if (p >= 0) {
				if (pos - p - dlen + dp[p] < del)
					del = pos - p - dlen + dp[p];
			} else
				if (pos - p - dlen < del)
					del = pos - p - dlen;
		}
	}
	return find;
}

void solve() {//dp
	int del;
	if (match(0, del))
		dp[0] = 0;
	else
		dp[0] = 1;
	for (int i = 1; i < len; i++) {
		if (match(i, del))
			dp[i] = min(del, dp[i - 1] + 1);
		else
			dp[i] = dp[i - 1] + 1;

	}
}

int main() {
	cin >> n >> len >> s;
	for (int i = 0; i < n; i++)
		cin >> dic[i];
	solve();
	cout << dp[len - 1];
	return 0;
}