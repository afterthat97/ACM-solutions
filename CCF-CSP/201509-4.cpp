//using tarjan algorithm.
#include <iostream>
#include <cmath>
#include <stack>

std::stack<int> s;
bool data[10001][10001], visited[10001], instack[10001];
int DFN[10001], low[10001], belong[10001];
int ne, np, index, count,ans;

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
		int nn = 0;
		do {
			nn++;
			j = s.top();
			s.pop();
			belong[j] = count;
			instack[j] = 0;
		} while (j != p);
		if (nn > 1)
			ans +=( (nn - 1)*nn )/ 2;
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

	std::cout << ans;
	return 0;
}