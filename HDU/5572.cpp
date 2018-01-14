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
//��������Ķ���
/////////////////////////////////////////////////////

struct point {
	double x, y;
	point(double x = 0, double y = 0):x(x), y(y) {}
};
point s, p;
typedef point vec;//ʵ���ϣ�vector������point�ı���
vec operator + (vec a, vec b) { return vec(a.x + b.x, a.y + b.y); }
vec operator - (point a, point b) { return vec(a.x - b.x, a.y - b.y); }
vec operator * (vec a, double p) { return vec(a.x * p, a.y * p); }
vec operator / (vec a, double p) { return vec(a.x / p, a.y / p); }
bool operator < (const point &a, const point &b) {//��Ҫʹ��>,��ʹ��<
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}
int dcmp(double x) {//��̬����
	if (fabs(x) < eps)
		return 0;
	else
		return x < 0 ? -1 : 1;
}
bool operator == (const point &a, const point &b) {
	return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y == 0);
}

/////////////////////////////////////////////////////
//��������Ļ�������
/////////////////////////////////////////////////////

double dot(vec a, vec b) { return a.x*b.x + a.y*b.y; };//���
double length(vec a) { return sqrt(dot(a, a)); }
double angle(vec a, vec b) {//�������н�
	double ans = dot(a, b) / length(a) / length(b);
	if (dcmp(ans - 1) == 0)ans = 1;
	if (dcmp(ans + 1) == 0)ans = -1;
	return acos(ans);
}
double angle(vec a) { return atan2(a.y, a.x); }//�����ļ���
double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }//���
double area(point a, point b, point c) {//��a,b,cΪ����������ε����
	return cross(b - a, c - a) / 2;
}
vec rotate(vec a, double rad) {//������a�������ʱ����תrad��
	return vec(a.x*cos(rad) - a.y*sin(rad), a.x*sin(rad) + a.y*cos(rad));
}
vec normal(vec a) {//a�ĵ�λ����(����ת90��,�ٳ��ȹ�һ)
	double l = length(a);
	return vec(-a.y / l, a.x / l);
}

point get_LL_intersection(point p, vec v, point q, vec w) {//��ֱ�߽���
	vec u = p - q;//ֱ��1:p+t*v,ֱ��2:q+t*w
	double t = cross(w, u) / cross(v, w);
	return p + v * t;
}
double dis_of_PL(point p, point a, point b) {//��p��ֱ��AB�ľ���
	vec v1 = b - a, v2 = p - a;
	return fabs(cross(v1, v2)) / length(v1);
}
double dis_of_PS(point p, point a, point b) {//��p���߶�AB�ľ���
	if (a == b) return length(p - a);
	vec v1 = b - a, v2 = p - a, v3 = p - b;
	if (dcmp(dot(v1, v2)) < 0)
		return length(v2);//����AP����
	else if (dcmp(dot(v1, v3)) > 0)
		return length(v3);//����BP����
	else
		return fabs(cross(v1, v2)) / length(v1);//���㷽��ֱͬ�߷���
}
bool P_on_L_left(point a, point p, vec v) {//�жϵ�a�Ƿ����߶�p+tv���
	return cross(v, a - p) > 0;
}
point get_PL_projection(point p, point a, point b) {//p����ֱ��AB�ϵ�ͶӰ��
	vec v = b - a;
	return a + v*(dot(v, p - a) / dot(v, v));
}
bool SS_intersection(point a1, point a2, point b1, point b2) {//�߶��ཻ�ж�
	double c1 = cross(a2 - a1, b1 - a1), c2 = cross(a2 - a1, b2 - a1),
		c3 = cross(b2 - b1, a1 - b1), c4 = cross(b2 - b1, a2 - b1);
	return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}
bool P_on_S(point p, point a1, point a2) {//�жϵ��Ƿ����߶���
	return dcmp(cross(a1 - p, a2 - p)) == 0 && dcmp(dot(a1 - p, a2 - p)) < 0;
}


struct circle {
	point c;
	double r;
	circle(point c, double r):c(c), r(r) {}
	point get_point(double rad) {//���Բ��һ�������
		return point(c.x + cos(rad)*r, c.y + sin(rad)*r);
	}
};
int get_LC_intersection(point pp, vec v, circle cir) //p+tvΪֱ�߲�������
{//t1,t2��Ž�����ֱ���ϵĲ���,sol��Ž���

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
