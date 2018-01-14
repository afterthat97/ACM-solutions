#include <iostream>
#include <stdio.h>
#include <set>
#include <map>
#define MAXM 1000005
#define MOD 1000000007
#define ll long long
using namespace std;

multiset<int> appear[MAXM];
map<multiset<int>, int> cnt;
ll jc[MAXM];
int n, m;

int main() {
	jc[0] = 1;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
		jc[i] = (jc[i - 1] * i) % MOD;

	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		for (int j = 0; j < num; j++) {
			int p;
			scanf("%d", &p);
			appear[p].insert(i);
		}
	}

	for (int i = 1; i <= m; i++)
		cnt[appear[i]]++;

	ll ans = 1;
	for (map<multiset<int>, int>::iterator it = cnt.begin();
			it != cnt.end(); it++)
				ans = (ans * jc[it->second]) % MOD;
	cout << ans << endl;
	return 0;
}
