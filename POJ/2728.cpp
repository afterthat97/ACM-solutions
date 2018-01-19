#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <cstring>
#define INF 999999999
using namespace std;

int np, ne;
int x[1005], y[1005], z[1005], vis[1005], pre[1005];
double len[1005][1005], dis[1005];

double prim(double ratio) {//ratio为比率，i和j的比率距离为fabs(z[i] - z[j]) - ratio * len[i][j]
	double all_cost = 0, all_len = 0;
	memset(vis, 0, sizeof(vis));
	fill(dis, dis + np, INF);
	dis[0] = 0, pre[0] = 0;
	for (int i = 0; i < np; i++) {
		double min_dis = INF;
		int k = -1;
		for (int j = 0; j < np; j++)
			if (!vis[j] && dis[j] < min_dis)
				min_dis = dis[k = j];
		vis[k] = 1;
		all_len += len[pre[k]][k], all_cost += fabs(z[pre[k]] - z[k]);
		for (int j = 0; j < np; j++)
			if (!vis[j] && (fabs(z[k] - z[j]) - ratio * len[k][j]) < dis[j]) {
				dis[j] = fabs(z[k] - z[j]) - ratio * len[k][j];
				pre[j] = k;
			}
	}
	return all_cost / all_len;
}

int main() {
	while (scanf("%d", &np) && np) {
		for (int i = 0; i < np; i++) scanf("%d %d %d", &x[i], &y[i], &z[i]);
		for (int i = 0; i < np - 1; i++)
			for (int j = i + 1; j < np; j++) {
				int dx = x[i] - x[j], dy = y[i] - y[j];
				len[i][j] = len[j][i] = sqrt(dx*dx + dy*dy);
			}
		double ans = 0;
		while (fabs(ans - prim(ans)) > 0.0001)//迭代法
			ans = prim(ans);
		printf("%.3f\n", ans);
	}
	return 0;
}