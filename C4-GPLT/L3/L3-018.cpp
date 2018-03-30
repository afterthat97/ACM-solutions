#include <stdio.h>
#include <cstring>
#include <iostream>
#include <queue>
#include <cmath>
#define inf 0x3f3f3f3f
#define maxn 10005
#define maxm 100005
#define fst first
#define snd second
using namespace std;

const int dx[8] = { 1, 0, -1, 0, 1, 1, -1, -1 };
const int dy[8] = { 0, 1, 0, -1, 1, -1, 1, -1 };

int np, ne, gsize, head[maxn];
double sp[maxn];
typedef pair<double, int> node;

struct edge {
    int to, next;
	double cost;
    edge(int t = 0, double c = 0, int n = 0): 
		to(t), cost(c), next(n) {}
}g[maxm];

inline void add_edge(int px, int py, double d) {
    g[gsize] = edge(py, d, head[px]);
    head[px] = gsize++;
}

double dijkstra(int ps, int pe) {
    priority_queue<node, vector<node>, greater<node> > q;
	for (int i = 0; i < maxn; i++)
		sp[i] = (i == ps ? 0 : inf);
    q.push(node(0, ps));
    while (!q.empty()) {
		node p = q.top(); q.pop();
		if (sp[p.snd] < p.fst) continue;
		for (int cnt = p.snd, i = head[p.snd]; ~i; i = g[i].next) 
			if (sp[g[i].to] > sp[cnt] + g[i].cost) {
				sp[g[i].to] = sp[cnt] + g[i].cost;
				q.push(node(sp[g[i].to], g[i].to));
			}
    }
	return sp[pe];
}

typedef pair<int, int> point;

int row, col, pic[105][105];
point st, ed;

int cross(point a, point b, point p) {
    return (b.fst - a.fst) * (p.snd - a.snd) - (b.snd - a.snd) * (p.fst - a.fst);
}

int left(point a, point b, point p) {
    return cross(a, b, p);
}

int getid(point a) {
	return a.fst * col + a.snd;
}

int main() {
    memset(head, -1, sizeof head); gsize = 0;
	cin >> row >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			scanf("%d", &pic[i][j]);
	cin >> st.snd >> st.fst >> ed.snd >> ed.fst;

	double ans = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			point n1(i, j);
			if (n1 != st && n1 != ed && left(st, ed, n1) == 0) continue;
			for (int k = 0; k < 8; k++) {
				point n2;
				n2.fst = n1.fst + dx[k];
				n2.snd = n1.snd + dy[k];
				if (n2.fst < 0 || n2.fst >= row || n2.snd < 0 || n2.snd >= col) continue;
				if (n2 != st && n2 != ed && left(st, ed, n2) == 0) continue;
				if (left(st, ed, n1) < 0 || left(st, ed, n2) < 0) continue;
				double sum = pic[n1.fst][n1.snd] + pic[n2.fst][n2.snd];
				double val = pic[n2.fst][n2.snd];
				if (k >= 4) val += sum * (sqrt(2.0) - 1.0);
				add_edge(getid(n1), getid(n2), val);
			}
		}
	ans += dijkstra(getid(st), getid(ed)) - 1.0 * pic[ed.fst][ed.snd]; 

	memset(head, -1, sizeof head); gsize = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			point n1(i, j);
			if (n1 != st && n1 != ed && left(st, ed, n1) == 0) continue;
			for (int k = 0; k < 8; k++) {
				point n2;
				n2.fst = n1.fst + dx[k];
				n2.snd = n1.snd + dy[k];
				if (n2.fst < 0 || n2.fst >= row || n2.snd < 0 || n2.snd >= col) continue;
				if (n2 != st && n2 != ed && left(st, ed, n2) == 0) continue;
				if (left(st, ed, n1) > 0 || left(st, ed, n2) > 0) continue;
				double sum = pic[n1.fst][n1.snd] + pic[n2.fst][n2.snd];
				double val = pic[n2.fst][n2.snd];
				if (k >= 4) val += sum * (sqrt(2.0) - 1.0);
				add_edge(getid(n1), getid(n2), val);
			}
		}
	ans += dijkstra(getid(st), getid(ed)) - 1.0 * pic[ed.fst][ed.snd]; 
	printf("%.2f\n", ans + pic[st.fst][st.snd] + pic[ed.fst][ed.snd]);
	return 0;
}
