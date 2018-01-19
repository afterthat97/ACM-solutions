#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
using namespace std;

string name[60];
bool s[60], used[60];

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i] >> name[i];

	for (int i = 0; i < n / 2; i++) {
		cout << name[i] << ' ';
		for (int j = n - 1; j >= n / 2; j--)
			if (!used[j])
				if (s[i] ^ s[j]) {
					used[j] = 1;
					cout << name[j] << endl;
					break;
				}
	}
	return 0;
}
