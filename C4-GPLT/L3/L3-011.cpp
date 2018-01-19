#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#define INF 0x3f3f3f3f
using namespace std;

struct node {
	int len, city, num, ways;
}sp[201];

int num[201], pre[201], order[201], len[201][201];
int np, ne, ps, pe, t;
string f[201], s1, s2;
bool visited[201];

int get_id(string s) {
	for (int i = 0; i < np; i++)
		if (f[i] == s) return i;
}

void work(int p, int j) {
	sp[j].len = len[p][j] + sp[p].len;
	sp[j].city = sp[p].city + 1;
	sp[j].num = sp[p].num + num[j];
	pre[j] = p;
}

void dijkstra() {
	for (int i = 0; i < np; i++)
		sp[i].len = (i == ps ? 0 : INF);

	visited[ps] = 1; pre[ps] = ps; sp[ps].ways = 1;
	int p = ps;
	for (int i = 1; i < np; i++) {
		for (int j = 0; j < np; j++)
			if (!visited[j])
				if (sp[j].len > len[p][j] + sp[p].len) {
					work(p, j);
					sp[j].ways = sp[p].ways;
				} else if (sp[j].len == len[p][j] + sp[p].len) {
					sp[j].ways += sp[p].ways;
					if (sp[j].city < sp[p].city + 1)
						work(p, j);
					else if (sp[j].city == sp[p].city + 1 && sp[j].num < sp[p].num + num[j])
						work(p, j);
				}
				int min = INF;
				for (int j = 0; j < np; j++)
					if (!visited[j] && sp[j].len < min)
						min = sp[p = j].len;
				visited[p] = 1;
	}
}

void output() {
	int p = pe, temp = 0;
	while (p != ps) {
		order[temp++] = p;
		p = pre[p];
	}
	cout << f[ps];
	for (int i = temp - 1; i >= 0; i--)
		cout << "->" << f[order[i]];
	cout << endl << sp[pe].ways << ' ' << sp[pe].len << ' ' << sp[pe].num;
}

int main() {
	cin >> np >> ne >> s1 >> s2;
	f[0] = s1; ps = 0;
	memset(len, INF, sizeof len);
	for (int i = 1; i < np; i++) {
		string s;
		cin >> s >> t;
		f[i] = s;
		num[i] = t;
	}
	pe = get_id(s2);
	for (int i = 0; i < ne; i++) {
		cin >> s1 >> s2 >> t;
		int x = get_id(s1), y = get_id(s2);
		len[x][y] = len[y][x] = t;
	}
	dijkstra();
	output();
	return 0;
}
