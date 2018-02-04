#include "all.h"

#define inf 0x3f3f3f3f
#define maxn 10005
#define maxm 100005
#define fst first
#define snd second
using namespace std;

int np, ps, gsize, head[maxn], sp[maxn];
typedef pair<int, int> node;
struct edge {
    int to, cost, next;
    edge(int t = 0, int c = 0, int n = 0): 
		to(t), cost(c), next(n) {}
}g[maxm];

inline void add_edge(int px, int py, int d) {
    g[gsize] = edge(py, d, head[px]);
    head[px] = gsize++;
}

void dijkstra() {
    priority_queue<node, vector<node>, greater<node> > q;
    memset(sp, inf, sizeof sp); sp[ps] = 0;
    q.push(node(0, ps));
    while (!q.empty()) {
		node p = q.top(); q.pop();
		if (sp[p.snd] < p.fst) continue;
		for (int cnt = p.snd, i = head[p.snd]; ~i; i = g[i].next) 
			if (sp[g[i].to] > max(sp[cnt], g[i].cost)) {
				sp[g[i].to] = max(sp[cnt], g[i].cost);
				q.push(node(sp[g[i].to], g[i].to));
			}
    }
}

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
		gsize = 0;
		memset(head, -1, sizeof head);
        int n = grid.size(); np = n * n;
		for (int i = 0; i < np; i++)
			for (int k = 0; k < 4; k++) {
				int nx = i / n + dx[k], ny = i % n + dy[k];
				if (nx >= 0 && ny >= 0 && nx < n && ny < n)
					add_edge(i, nx * n + ny, max(grid[nx][ny], grid[i / n][i % n]));
			}
		ps = 0;
		dijkstra();
		return np == 1 ? grid[0][0] : sp[np - 1];
    }
};

int main() {
	int n; cin >> n;
	vector<vector<int>> grid(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> grid[i][j];
	cout << Solution().swimInWater(grid) << endl;
	return 0;
}
