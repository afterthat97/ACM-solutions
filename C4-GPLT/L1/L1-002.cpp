#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int n; char ch;
    cin >> n >> ch;
    n--; int base = 3, lv = 1;
    while (n > 0) {
		if (n - base - base  >= 0) {
			lv++;
			n -= base + base;
			base += 2;
		} else break;
    }
    for (int i = lv; i > 0; i--) {
	for (int j = 0; j < lv - i; j++) cout << ' ';
	    for (int j = 0; j < i * 2 - 1; j++) cout << ch;
		cout << endl;
	}
	for (int i = 2; i <= lv; i++) {
		for (int j = 0; j < lv - i; j++) cout << ' ';
		for (int j = 0; j < i * 2 - 1; j++) cout << ch;
		cout << endl;
	}
	cout << n << endl;
	return 0;
}
