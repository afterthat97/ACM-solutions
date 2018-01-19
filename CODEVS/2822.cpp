//using tarjan algorithm¡£
#include <iostream>
#include <cmath>
#include <stack>

std::stack<int> s;
int data[1001][1001], gnew[1001][1001], visited[1001], instack[1001];
int DFN[1001], low[1001], belong[1001];
int ne, np, index, count, single, love;

void tarjan(int p) {
	index++;
	DFN[p] = low[p] = index;
	s.push(p);
	visited[p] = instack[p] = 1;

	for (int i = 1; i <= np; i++)
		if (data[p][i]) {
			if (!visited[i]) {
				tarjan(i);
				low[p] = low[p] > low[i] ? low[i] : low[p];
				//low[p] = min(low[p], low[i]);
			} else if (instack[i])
				low[p] = low[p] > DFN[i] ? DFN[i] : low[p];
			//low[p] = min(low[p], DFN[i]);
		}

	if (DFN[p] == low[p]) {
		count++;
		int j;
		single = 0;
		do {
			single++;
			if (single == 2)love++;
			j = s.top();
			s.pop();
			belong[j] = count;
			instack[j] = 0;
		} while (j != p);
	}
}

int main() {
	std::cin >> np >> ne;
	for (int i = 0; i < ne; i++) {
		int px, py;
		std::cin >> px >> py;
		data[px][py] = 1;
	}
	while (!s.empty())
		s.pop();

	for (int i = 1; i <= np; i++)
		if (!visited[i])
			tarjan(i);

	for (int i = 1; i <= np; i++)
		for (int j = 1; j <= np; j++)
			if (data[i][j] && belong[i] != belong[j]) {
				gnew[belong[i]][belong[j]] = 1;
				gnew[belong[i]][0]++;
			}

	std::cout << love << std::endl;
	int nnull = 0;
	for (int i = 1; i <= count; i++)
		if (!gnew[i][0])
			nnull++;

	if (nnull > 1) {
		std::cout << -1;
		return 0;
	}
	for (int i = 1; i <= count; i++)
		if (!gnew[i][0]) {
			int num = 0;
			for (int j = 1; j <= np; j++)
				if (belong[j] == i)
					num++;
			if (num == 1) {
				std::cout << -1;
				return 0;
			}

			for (int j = 1; j <= np; j++)
				if (belong[j] == i) {
					std::cout << j;
					num--;
					if (num) std::cout << ' ';

				}
			return 0;
		}

	return 0;
}