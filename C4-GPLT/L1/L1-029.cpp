#include <stdio.h>

int main() {
	double ans;
	scanf("%lf", &ans);
	ans -= 100;
	ans *= 0.9;
	ans *= 2;
	printf("%.1lf", ans);
	return 0;
}
