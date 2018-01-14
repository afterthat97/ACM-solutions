#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#define min(x,y) (x>y?y:x)
#define max(x,y) (x>y?x:y)
const double PI = 3.14159265358979;
const double EPS = 1e-8;
using namespace std;

struct Point {
	double x, y;
	Point(double x = 0, double y = 0):x(x), y(y) {}
};

int sign(double x) {
	if (fabs(x) < EPS) return 0;
	else return x < 0 ? -1 : 1;
}

typedef Point Vector;

Vector operator - (Point A, Point B) { return Vector(A.x - B.x, A.y - B.y); }

double Dot(Vector A, Vector B) { return A.x*B.x + A.y*B.y; }
double Length(Vector A) { return sqrt(Dot(A, A)); }
double Angle(Vector A, Vector B) { return acos(Dot(A, B) / Length(A) / Length(B)); }

struct Polygon {
	Point *p;
	double *rad;
	double *len;
	int size;
	Polygon(int x = 0) {
		p = new Point[x];
		rad = new double[x];
		len = new double[x];
		size = x;
	}
	int next(int x) { return (x + 1) % size; }
	int pre(int x) { return (x + size - 1) % size; }
	void getlen() {
		for (int i = 0; i < size; i++)
			len[i] = fabs(Length(p[next(i)] - p[i]));
	}
	void getrad() {
		for (int i = 0; i < size; i++)
			rad[i] = fabs(Angle(p[pre(i)] - p[i], p[next(i)] - p[i]));
	}
};

int m, n;

bool equel(double x, double y, double a, double b) {
	double temp;
	if (sign(y - x) > 0) {
		temp = x;
		x = y;
		y = temp;
	}
	if (sign(b - a) > 0) {
		temp = a;
		a = b;
		b = temp;
	}
	if (sign(a - x) != 0 || sign(b - y) != 0) return false;
	return true;
}

bool run1(Polygon x, Polygon y) {//3
	int i, j, t = -1, tt = -1, sum1 = 0, sum2 = 0;
	double a, b, aa, bb;
	x.getrad(); y.getrad();
	for (i = 0; i < 3; i++) {
		if (sign(x.rad[i] * 2 - PI) == 0) //sign
			t = i;
		if (sign((x.p[i] - x.p[x.pre(i)]).x) != 0 && sign((x.p[i] - x.p[x.pre(i)]).y) != 0)
			sum1++;
		if (sign(y.rad[i] * 2 - PI) == 0)
			tt = i;
		if (sign((y.p[i] - y.p[y.pre(i)]).x) != 0 && sign((y.p[i] - y.p[y.pre(i)]).y) != 0)
			sum2++;
	}
	if (sum1 != 1 || sum2 != 1) return false;
	if (t == -1 || tt == -1) return false;
	x.getlen(); y.getlen();
	a = x.len[t];
	b = sign(x.len[x.pre(t)] - x.len[x.next(t)]) < 0 ? x.len[x.pre(t)] : x.len[x.next(t)];
	aa = y.len[tt];
	bb = sign(y.len[y.pre(tt)] - y.len[y.next(tt)]) < 0 ? y.len[y.pre(tt)] : y.len[y.next(tt)];
	if (equel(a, b, aa, bb)) return true;
	else return false;
}

bool run2(Polygon x, Polygon y) //3 4
{
	int i, j, mark = 0, t = -1;
	double a, b, c, aa, bb;//aa>bb
	x.getrad(); y.getrad();
	for (i = 0; i < 3; i++)
		if (sign(x.rad[i] * 2 - PI) == 0) //sign
			t = i;
	if (t == -1) return false;
	x.getlen(); y.getlen();
	aa = x.len[t];
	bb = x.len[x.next(t)] < x.len[x.pre(t)] ? x.len[x.next(t)] : x.len[x.pre(t)];//min

	for (i = 0, t = -1; i < 4; i++)
		if (sign(y.rad[i] * 2 - PI) == 0 && sign(y.rad[y.next(i)] * 2 - PI) == 0)
			t = i;
	if (t == -1) return false;
	a = y.len[t];
	b = y.len[y.pre(t)];
	c = y.len[y.next(t)];

	if (equel(aa, bb, a, fabs(b - c))) return true;
	else return false;
}

bool run3(Polygon x, Polygon y) {//44
	int i, j, t = -1, tt = -1;
	double a, aa, b, bb, c, cc, temp;
	x.getrad(); y.getrad();
	x.getlen(); y.getlen();
	for (i = 0; i < 4; i++)
		if (sign(x.rad[i] * 2 - PI) == 0 && sign(x.rad[x.next(i)] * 2 - PI) == 0)
			t = i;
	for (i = 0; i < 4; i++)
		if (sign(y.rad[i] * 2 - PI) == 0 && sign(y.rad[y.next(i)] * 2 - PI) == 0)
			tt = i;
	if (tt == -1 || t == -1) return false;

	a = x.len[t]; b = x.len[x.pre(t)]; c = x.len[x.next(t)];
	aa = y.len[tt]; bb = y.len[y.pre(tt)]; cc = y.len[y.next(tt)];
	if (sign(a - aa) != 0) return false;
	if (sign(fabs(b - c) - fabs(bb - cc)) != 0) return false;
	return true;
}

bool run4(Polygon x, Polygon y)//35
{
	int i, j, mark = 0, t = -1, tt = -1;
	double a, b, c, d, temp, aa, bb;//aa>bb
	x.getrad(); y.getrad();
	for (i = 0; i < 3; i++)
		if (sign(x.rad[i] * 2 - PI) == 0)
			tt = i;
	if (tt == -1) return false;
	x.getlen(); y.getlen();
	aa = x.len[tt];
	bb = x.len[x.next(tt)] < x.len[x.pre(tt)] ? x.len[x.next(tt)] : x.len[x.pre(tt)];

	for (i = 0; i < 5; i++)
		if (sign(y.rad[i] * 2 - PI) < 0) return false;

	for (i = 0; i < 5; i++)
		if (sign(y.rad[i] * 2 - PI) == 0 && sign(y.rad[y.next(i)] * 2 - PI) == 0 && sign(y.rad[y.pre(i)] * 2 - PI) == 0)
			t = i;
	if (t == -1) return false;
	a = y.len[t]; b = y.len[y.pre(t)];
	d = y.len[y.next(t)]; c = y.len[y.pre(y.pre(t))];
	if (equel(fabs(a - c), fabs(b - d), aa, bb)) return true;
	c = y.len[y.next(y.next(t))];
	if (equel(fabs(a - c), fabs(b - d), aa, bb)) return true;
	else return false;
}

int main() {
	bool res;
	int T;
	cin >> T;
	while (T--) {
		scanf("%d", &n);
		Polygon x(n);
		for (int i = 0; i < n; i++)
			scanf("%lf%lf", &x.p[i].x, &x.p[i].y);
		scanf("%d", &m);
		Polygon y(m);
		for (int i = 0; i < m; i++)
			scanf("%lf%lf", &y.p[i].x, &y.p[i].y);

		res = false;
		if (min(m, n) == 3) {
			if (max(m, n) == 3)
				res = run1(x, y);//both 3
			if (max(m, n) == 4) {
				if (n == 3) res = run2(x, y);//3 4
				else res = run2(y, x);
			}
			if (max(m, n) == 5) {//3 5
				if (n == 3) res = run4(x, y);
				else res = run4(y, x);
			}
		} else if (min(n, m) == 4 && m + n == 8) res = run3(x, y);//4 4

		if (res) cout << "YES" << endl;
		else cout << "NO" << endl;

	}
}
