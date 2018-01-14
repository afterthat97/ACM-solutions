#include <iostream>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
using namespace std;

int a[105];
int sum = 0;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum == 0) {
		int cnt = 0;
		bool yes = 0;
		for (int i = 0; i < n; i++) {
			cnt += a[i];
			if (cnt != 0) {
				cout << "YES\n2\n1 " << i + 1 << endl;
				cout << i + 2 << ' ' << n << endl;
				yes = 1;
				exit(0);
			}
		}
		if (yes == 0) cout << "NO\n"; 
	} else {
		cout << "YES\n1\n1 " << n << endl;
	}

	return 0;
}
