#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
using namespace std;

string id[1005];
int n, m, sj[1005], ks[1005];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> id[i] >> sj[i] >> ks[i];
	cin >> m;
	for (int i = 0; i < m; i++) {
		int q; cin >> q;
		for (int j = 0; j < n; j++)
			if (sj[j] == q) {
				cout << id[j] << ' ' << ks[j] << endl;;
				break;
			}
	}
	return 0;
}
