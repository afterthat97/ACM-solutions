#include <iostream>
#include <stdio.h>
using namespace std;

int a, b;

int main() {
	cin >> a >> b;
	printf("%d/", a);
	if (b < 0) printf("(%d)=", b);
	else printf("%d=", b);
	if (b == 0) printf("Error");
	else printf("%.2f", (a * 1.0) / b);
	return 0;
}
