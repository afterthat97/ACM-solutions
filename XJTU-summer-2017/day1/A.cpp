#include <iostream>
using namespace std;

int n;

int main() {
	while (cin >> n) {
		cout << n / 2 << endl;
		for (int i = 0; i < n / 2 - 1; i++) cout << "2 ";
		if (n & 1) puts("3"); else puts("2");
	}
	return 0;
}
