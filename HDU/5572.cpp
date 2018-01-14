#include <iostream>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <vector>
#define pause cin.get();cin.get();
/////////////////////////////////////////////////////
//L = line, C = circle, S = segment, P = point
/////////////////////////////////////////////////////

using namespace std;
const double eps = 1e-8;
const double pi = 3.14159265358979;
/////////////////////////////////////////////////////
//点和向量的定义
/////////////////////////////////////////////////////

struct point {
	double x, y;
	point(double x = 0, double y = 0):x(x), y(y) {}
};
point s, p;
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

/////////////////////////////////////////////////////
//点和向量的基本运算
/////////////////////////////////////////////////////

double dot(vec a, vec b) { return a.x*b.x + a.y*b.y; };//点积
double length(vec a) { return sqrt(dot(a, a)); }
double angle(vec a, vec b) {//俩向量夹角
	double ans = dot(a, b) / length(a) / length(b);
	if (dcmp(ans - 1) == 0)ans = 1;
	if (dcmp(ans + 1) == 0)ans = -1;
	return acos(ans);
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

point get_LL_intersection(point p, vec v, point q, vec w) {//俩直线交点
	vec u = p - q;//直线1:p+t*v,直线2:q+t*w
	double t = cross(w, u) / cross(v, w);
	return p + v * t;
}
double dis_of_PL(point p, point a, point b) {//点p到直线AB的距离
	vec v1 = b - a, v2 = p - a;
	return fabs(cross(v1, v2)) / length(v1);
}
double dis_of_PS(point p, point a, point b) {//点p到线段AB的距离
	if (a == b) return length(p - a);
	vec v1 = b - a, v2 = p - a, v3 = p - b;
	if (dcmp(dot(v1, v2)) < 0)
		return length(v2);//返回AP长度
	else if (dcmp(dot(v1, v3)) > 0)
		return length(v3);//返回BP长度
	else
		return fabs(cross(v1, v2)) / length(v1);//计算方法同直线方法
}
bool P_on_L_left(point a, point p, vec v) {//判断点a是否在线段p+tv左侧
	return cross(v, a - p) > 0;
}
point get_PL_projection(point p, point a, point b) {//p点在直线AB上的投影点
	vec v = b - a;
	return a + v*(dot(v, p - a) / dot(v, v));
}
bool SS_intersection(point a1, point a2, point b1, point b2) {//线段相交判定
	double c1 = cross(a2 - a1, b1 - a1), c2 = cross(a2 - a1, b2 - a1),
		c3 = cross(b2 - b1, a1 - b1), c4 = cross(b2 - b1, a2 - b1);
	return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}
bool P_on_S(point p, point a1, point a2) {//判断点是否在线段上
	return dcmp(cross(a1 - p, a2 - p)) == 0 && dcmp(dot(a1 - p, a2 - p)) < 0;
}


struct circle {
	point c;
	double r;
	circle(point c, double r):c(c), r(r) {}
	point get_point(double rad) {//获得圆上一点的坐标
		return point(c.x + cos(rad)*r, c.y + sin(rad)*r);
	}
};
int get_LC_intersection(point pp, vec v, circle cir) //p+tv为直线参数方程
{//t1,t2存放交点在直线上的参数,sol存放交点

	double d = dis_of_PL(cir.c, pp, pp + v);
	if (dcmp(d - cir.r) > 0) {
		return 0;
	} else if (dcmp(d - cir.r) == 0) {
		return 1;
	} else {
		point proj = get_PL_projection(cir.c, pp, pp + v);
		vec ev = v / length(v);
		double dd = sqrt(cir.r*cir.r - d*d);
		if (dcmp(d) == 0) {
			p = cir.c - ev*cir.r;
			return 2;
		}
		point p1 = proj + ev*dd;
		point p2 = proj - ev*dd;
		if (P_on_L_left(p1, cir.c, proj - cir.c))
			if (P_on_L_left(s, cir.c, proj - cir.c))
				p = p1;
			else
				p = p2;
		else
			if (P_on_L_left(s, cir.c, proj - cir.c))
				p = p2;
			else
				p = p1;
		return 2;
	}
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		double ox, oy, r;
		scanf("%lf %lf %lf", &ox, &oy, &r);
		vec v;
		scanf("%lf %lf %lf %lf", &s.x, &s.y, &v.x, &v.y);
		point b;
		scanf("%lf %lf", &b.x, &b.y);
		circle c(point(ox, oy), r);
		int num = get_LC_intersection(s, v, c);
		if (num == 2) {
			double rad = angle(p - c.c, s - p);
			vec new1 = rotate(p - c.c, rad);
			vec new2 = rotate(p - c.c, -rad);

			if (P_on_S(b, s, p)) {
				cout << "Case #" << i << ": Yes\n";
				continue;
			}

			if (dcmp(cross(new1, s - p)) == 0) {//use new2
				double cro = cross(new2, b - p);
				double d = dot(new2, b - p);
				if (dcmp(cro) == 0 && dcmp(d) >= 0) {
					cout << "Case #" << i << ": Yes\n";
				} else
					cout << "Case #" << i << ": No\n";
			} else {
				double cro = cross(new1, b - p);
				double d = dot(new1, b - p);
				if (dcmp(cro) == 0 && dcmp(d) >= 0) {
					cout << "Case #" << i << ": Yes\n";
				} else
					cout << "Case #" << i << ": No\n";
			}
		} else {
			double cro = cross(v, b - s);
			double d = dot(v, b - s);
			if (dcmp(cro) == 0 && dcmp(d) >= 0) {
				cout << "Case #" << i << ": Yes\n";
			} else
				cout << "Case #" << i << ": No\n";
		}
	}
	pause;
	return 0;
}
