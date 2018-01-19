//POJ 1273, using edmonds-karp algorithm
#include <iostream>
#include <queue>
#define INF 999999999;

int np, ne;
int data[201][201], flow[201], path[201];

int edmonds_karp(int ps, int pe) {
	int max_flow = 0;
	std::queue<int> q;
	while (!q.empty())
		q.pop();
	while (1) {
		memset(flow, 0, sizeof(flow));
		flow[ps] = INF;
		q.push(ps);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (int v = 1; v <= np; v++)
				if (!flow[v] && data[u][v]) {
					path[v] = u;
					q.push(v);
					flow[v] = flow[u]>data[u][v] ? data[u][v] : flow[u];
				}
		}
		if (flow[pe] == 0)
			return max_flow;
		for (int p = pe; p != ps; p = path[p]) {
			data[path[p]][p] -= flow[pe];
			data[p][path[p]] += flow[pe];
		}
		max_flow += flow[pe];
	}
}


int main() {
	while (scanf("%d%d", &ne, &np) != EOF) {
		memset(data, 0, sizeof(data));
		for (int i = 0; i < ne; i++) {
			int u, v, w;
			std::cin >> u >> v >> w;
			data[u][v] += w;
		}
		std::cout << edmonds_karp(1, np) << std::endl;
	}
	return 0;
}
