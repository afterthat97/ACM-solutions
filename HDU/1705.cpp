#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#define gcd __gcd
using namespace std;

struct point { int x, y; } p[3];

point operator - (const point& p1, const point& p2) {
	return {p1.x - p2.x, p1.y - p2.y};
}

inline int onb(const point& p1, const point& p2) {
	return gcd(abs(p2.x - p1.x), abs(p2.y - p1.y)) + 1;
}

inline int cross(const point& p1, const point& p2) {
	return p1.x * p2.y - p1.y * p2.x;
}

int main() {
	while (scanf("%d %d %d %d %d %d",
		&p[0].x, &p[0].y, &p[1].x, &p[1].y, &p[2].x, &p[2].y) == 6) {
		int s = abs(cross(p[2] - p[0], p[1] - p[0]));
		if (s == 0) break;
		int b = onb(p[0], p[1]) + onb(p[1], p[2]) + onb(p[2], p[0]) - 3;
		printf("%d\n", (s - b) / 2 + 1);
	}

	return 0;
}
