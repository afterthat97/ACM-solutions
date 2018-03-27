#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int n, cnt = 1;
	while (scanf("%d", &n) == 1)
		if (n == 250) {
			cout << cnt << endl;
			return 0;
		} else
			cnt++;
	return 0;
}
