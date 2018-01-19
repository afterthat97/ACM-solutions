#include <iostream>
#include <stdlib.h>
using namespace std;

int ne, np;
int num = 0;
short int a[8001][8001] = {};
bool aa[8001][8001];
bool vis[8001][8001] = {};
short int way[100001];

void print() {
	for (int i = 0; i <= num; i++)
		cout << way[i] << ' ';
	exit(0);
}

void dfs(int p, int from) {
	for (int i = 1; i <= a[p][0]; i++) {
		int q = a[p][i];
		if (!vis[p][q] && !vis[q][p]) {
			vis[p][q] = 1;
			vis[q][p] = 1;
			num++;
			way[num] = q;
			if (num == ne) {
				print();
			}
			dfs(q, p);
		}
	}
	vis[from][p] = 0;
	vis[p][from] = 0;
	num--;
}

int main() {
	cin >> np >> ne;
	for (int i = 0; i<ne; i++) {
		int px, py;
		cin >> px >> py;
		aa[px][py] = 1;
		aa[py][px] = 1;
	}
	for (int i = 1; i <= np; i++) {
		for (int j = 1; j <= np; j++)
			if (aa[i][j]) {
				a[i][0]++;
				a[i][a[i][0]] = j;
			}
	}
	way[0] = 1;
	dfs(1, 1);
	cout << -1;
	return 0;
}