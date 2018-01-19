//from foreyes_1001
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#define MAXN 100000
using namespace std;

int fa[MAXN];
int mo[MAXN];
int sex[MAXN];
int tot = 1;
map<int, int> u;
queue<int> v[2];

void clear() {
	for (int i = 0; i < 2; i++)
		while (!v[i].empty()) v[i].pop();
}

bool check(int a, int b) {
	int i, j, mark = 0, x;
	clear();
	v[0].push(a);
	for (i = 0; i < 5; i++) {
		while (!v[mark].empty()) {
			x = v[mark].front();
			v[mark].pop();
			u[x] = tot;
			if (i != 4) {
				if (fa[x] != -1)
					v[mark ^ 1].push(fa[x]);
				if (mo[x] != -1)
					v[mark ^ 1].push(mo[x]);
			}
		}
		mark = mark ^ 1;
	}
	clear();
	mark = 0;
	v[0].push(b);
	for (i = 0; i < 5; i++) {
		while (!v[mark].empty()) {
			x = v[mark].front();
			v[mark].pop();
			if (u[x] == tot) return false;
			if (i != 4) {
				if (fa[x] != -1)
					v[mark ^ 1].push(fa[x]);
				if (mo[x] != -1)
					v[mark ^ 1].push(mo[x]);
			}
		}
		mark = mark ^ 1;
	}
	return true;
}

int main() {
	int i, j, a, b, c, n, m;
	char ch;
	cin >> n;
	memset(fa, -1, sizeof(fa));
	memset(mo, -1, sizeof(mo));
	for (i = 0; i < n; i++) {
		scanf("%d %c%d%d", &a, &ch, &b, &c);
		fa[a] = b; mo[a] = c;
		sex[a] = ch == 'F' ? 1 : 2;//1 F Ů 
		if (fa[a] != -1) sex[fa[a]] = 2;
		if (mo[a] != -1) sex[mo[a]] = 1;
	}
	cin >> m;
	for (i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		if (sex[a] == sex[b]) {
			printf("Never Mind\n");
			continue;
		}
		if (check(a, b)) printf("Yes\n");
		else printf("No\n");
		tot++;
	}
}
