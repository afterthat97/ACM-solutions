#include <iostream>
#include <stdio.h>
using namespace std;

int l, r;

int main() {
	cin >> l >> r;
	int cnt = 0, sum = 0;
	for (int i = l ; i <= r; i++) {
		printf("%5d", i);
		cnt++;
		if (cnt == 5) {
			cout << endl;
			cnt = 0;
		}
		sum += i;
	}
	if (cnt) cout << endl;
	printf("Sum = %d\n", sum);
	return 0;
}
