#include <iostream>
#include <stdio.h>
#include <cstring>
#include <map>
#define ll long long
using namespace std;

map<int, ll> tot;
char s[100005];
bool cnt[26];

int dec() {
	int ans = 0;
	for (int i = 0, base = 1; i < 26; i++) {
		ans += cnt[i] * base;
		base <<= 1;
	}
	return ans;
}

int main() {
	int T; cin >> T;
	for (int idx = 0; idx < T; idx++) {
		tot.clear(); tot[0] = 1;
		memset(cnt, 0, sizeof cnt);
		scanf("%s", s);
		ll ans = 0;
		int len = strlen(s);
		for (int i = 0; i < len; i++) {
			int c = s[i] - 'a';
			if (cnt[c]) cnt[c] = 0; else cnt[c] = 1;
			int now = dec();
			ans += tot[now];
			tot[now]++;
		}
		cout << ans << endl;
	}
	return 0;
}