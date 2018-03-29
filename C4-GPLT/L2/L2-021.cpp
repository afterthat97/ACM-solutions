#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cstring>
#include <map>
using namespace std;

struct person {
	string name;
	int diff;
	double avg;
}a[105];

bool operator < (const person& x, const person& y) {
	if (x.diff != y.diff) return x.diff > y.diff;
	return x.avg < y.avg;
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		map<int, int> appear;
		cin >> a[i].name;
		int k; cin >> k;
		for (int j = 0; j < k; j++) {
			int id; cin >> id;
			if (appear[id] == 0) {
				appear[id]++;
				a[i].diff++;
			}
		}
		a[i].avg = (1.0) * k / (1.0) * a[i].diff;	
	}
	sort(a, a + n);
	if (n == 1)
		cout << a[0].name << " - -\n";
	else if (n == 2)
		cout << a[0].name << a[1].name << " -\n";
	else {
		cout << a[0].name;
		for (int i = 1; i < 3; i++)
			cout << ' ' << a[i].name;
	}	
	
	return 0;
}
