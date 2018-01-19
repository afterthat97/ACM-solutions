#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define INF 999999999
#define pause cin.get();cin.get();
#define read(i) scanf("%d", &i);
#define ln printf("\n");
using namespace std;

const double eps = 1e-10;
const double pi = 3.14159265358979;

struct point {
	int x, y;
	point(int x = 0, int y = 0):x(x), y(y) {}
};
typedef point vec;//实现上，vector不过是point的别名
vec operator + (vec a, vec b) { return vec(a.x + b.x, a.y + b.y); }
vec operator - (point a, point b) { return vec(a.x - b.x, a.y - b.y); }
vec operator * (vec a, double p) { return vec(a.x * p, a.y * p); }
vec operator / (vec a, double p) { return vec(a.x / p, a.y / p); }
bool operator < (const point &a, const point &b) {//不要使用>,而使用<
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}
int dcmp(double x) {//三态函数
	if (fabs(x) < eps)
		return 0;
	else
		return x < 0 ? -1 : 1;
}
bool operator == (const point &a, const point &b) {
	return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y == 0);
}

double dot(vec a, vec b) { return a.x*b.x + a.y*b.y; };//点积
double length(vec a) { return sqrt(dot(a, a)); }
double angle(vec a, vec b) {//俩向量夹角
	return acos(dot(a, b)) / length(a) / length(b);
}
double angle(vec a) { return atan2(a.y, a.x); }//向量的极角
double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }//叉积
double area(point a, point b, point c) {//以a,b,c为顶点的三角形的面积
	return cross(b - a, c - a) / 2;
}
vec rotate(vec a, double rad) {//将向量a绕起点逆时针旋转rad角
	return vec(a.x*cos(rad) - a.y*sin(rad), a.x*sin(rad) + a.y*cos(rad));
}
vec normal(vec a) {//a的单位法线(即左转90度,再长度归一)
	double l = length(a);
	return vec(-a.y / l, a.x / l);
}


int convex_hull(point *p, int n, point *ch) {//n个点组成的p[]的凸包,存放在ch[]中
	sort(p, p + n);
	int m = 0;
	for (int i = 0; i < n; i++) {
		while (m > 1 && cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) m--;
		ch[m++] = p[i];
	}
	int k = m;
	for (int i = n - 2; i >= 0; i--) {
		while (m > k && cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) m--;
		ch[m++] = p[i];
	}
	if (n > 1) m--;
	return m;
}

point p[100000], ans[100000];

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d %d", &p[i].x, &p[i].y);
	int m = convex_hull(p, n, ans);
	double c = 0;
	for (int i = 0; i < m - 1; i++)
		c += length(ans[i + 1] - ans[i]);
	c += length(ans[m - 1] - ans[0]);
	printf("%.1lf", c);
	return 0;
}