#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

const double e = 0.916297857297023;
double xx1, xx2, yy1, yy2;

int main() {
	cin >> xx1 >> yy1 >> xx2 >> yy2;
	double d = (xx2 - xx1) * (xx2 - xx1) + (yy2 - yy1) * (yy2 - yy1);
	printf("%.10lf", e*d);
	return 0;
}
