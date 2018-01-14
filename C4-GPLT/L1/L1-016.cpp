#include <iostream>
#include <stdio.h>
using namespace std;

char s[20];
int q[20] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char j[15] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

int main() {
	int n; cin >> n;
	bool succ = 1;
	for (int i = 0; i < n; i++) {
		cin >> s;
		int sum = 0;
		for (int i = 0; i < 17; i++)
			sum += q[i] * (s[i] - 48);
		sum %= 11;
		if (s[17] != j[sum]) {
			cout << s << endl;
			succ = 0;
		}
	}
	if (succ) cout << "All passed\n";
	return 0;
}
