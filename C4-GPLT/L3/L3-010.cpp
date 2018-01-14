#include <stdio.h>
#include <queue>

int n, t, size;
int l[50], r[50], tree[50], order[50];

void ins(int x, int pos) {//建树，插入节点
	if (tree[pos] > x) {//r
		if (r[pos])
			ins(x, r[pos]);
		else
			r[pos] = size;
	} else if (tree[pos] < x) {//l
		if (l[pos])
			ins(x, l[pos]);
		else
			l[pos] = size;
	}
}

void bfs() {//层序遍历
	size = 0;
	std::queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		order[++size] = tree[now];
		if (tree[now]) {//now不是NULL节点
			q.push(l[now]);
			q.push(r[now]);
		}
	}
}

bool judge() {//判断是否是完全二叉树
	int pos;
	for (int i = size; i >= 1; i--)
		if (order[i]) {//如果i是NULL节点
			pos = i; break;
		}
	for (int i = pos; i >= 1; i--)
		if (order[i] == 0)
			return false;
	return true;
}

void output() {
	printf("%d", order[1]);
	for (int i = 2; i <= size; i++)
		if (order[i])
			printf(" %d", order[i]);
	if (judge())
		printf("\nYES");
	else
		printf("\nNO");
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		tree[++size] = t;
		ins(t, 1);
	}
	bfs();
	output();
	return 0;
}