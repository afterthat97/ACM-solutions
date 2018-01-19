#include <iostream>
#include <stdio.h>
using namespace std;

int a, b;

int main() {
	scanf("%d:%d", &a, &b);
	if (a >= 0 && a <= 11)
		printf("Only %02d:%02d.  Too early to Dang.\n", a, b);
	else if (a == 12 && b == 0)
		printf("Only %02d:%02d.  Too early to Dang.\n", a, b);
	else {
		b--;
		if (b < 0) a--;
		for (int i = 0; i < a - 11; i++)
			cout << "Dang";
	}
	return 0;
}
