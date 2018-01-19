#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAXN 100005
#define MAXM 50005
using namespace std;

struct node {
	int l, r, k, id;
    node() {}
    node(int L, int R, int K, int ID) {
        l = L; r = R; k = K; id = ID;
    }
}floor[30][MAXM];

struct {
    int l, r, ql, qr, f;
}que[MAXM << 2];

struct dat {
    int val, id;
}raw[MAXN];

bool cmp1(const dat& a, const dat& b) { return a.val < b.val; }

int tree[MAXN], a[MAXN], ans[MAXM], n, m;

inline int sum(int x) {
	int ans = 0;
	for (; x > 0; x -= (x & -x))
		ans += tree[x];
	return ans;
}

inline void add(int x, int val) {
	for (; x <= n; x += (x & -x))
		tree[x] += val;
}

int getint() {
    int x = 0, flag = 0; char ch = getchar();
    for(; !isdigit(ch); ch = getchar())
        if (ch == '-') flag = 1;
    for(; isdigit(ch); ch = getchar())
        x = x * 10 + ch - '0';
    return flag ? -x : x;
}

int main() {
    n = getint(); m = getint();
    for (int i = 1; i <= n; i++) {
        raw[i].val = getint();
        raw[i].id = i;
    }
    sort(raw + 1, raw + n + 1, cmp1);
    for (int i = 1; i <= n; i++)
        a[raw[i].id] = i;

	que[1].l = 1; que[1].r = n;
    que[1].ql = 0; que[1].qr = m - 1;
    for (int i = 0; i < m; i++) {
        floor[0][i].l = getint();
        floor[0][i].r = getint();
        floor[0][i].k = getint();
        floor[0][i].id = i;
	}
    
    for (int now = 1, cnt = 1; now <= cnt; now++) {
		if (que[now].l == que[now].r || que[now].ql > que[now].qr) {
			for (int i = que[now].ql; i <= que[now].qr; i++)
				ans[floor[que[now].f][i].id] = que[now].l;
			continue;
		}
		int mid = (que[now].l + que[now].r) >> 1;
		for (int i = que[now].l; i <= mid; i++)
            add(raw[i].id, 1);
        int flag1 = que[now].ql - 1, flag2 = que[now].qr + 1;
        for (int i = que[now].ql; i <= que[now].qr; i++) {
            int kth = sum(floor[que[now].f][i].r) - sum(floor[que[now].f][i].l - 1);
			if (floor[que[now].f][i].k <= kth)
                floor[que[now].f + 1][++flag1] = floor[que[now].f][i];
			else {
                floor[que[now].f][i].k -= kth;
                floor[que[now].f + 1][--flag2] = floor[que[now].f][i];
            }
		}
        que[cnt + 1].l = que[now].l;
        que[cnt + 1].r = mid;
        que[cnt + 1].f = que[now].f + 1;
        que[cnt + 1].ql = que[now].ql;
        que[cnt + 1].qr = flag1;
        
        que[cnt + 2].l = mid + 1;
        que[cnt + 2].r = que[now].r;
        que[cnt + 2].f = que[now].f + 1;
        que[cnt + 2].ql = flag1 + 1;
        que[cnt + 2].qr = que[now].qr;
        
        for (int i = que[now].l; i <= mid; i++) add(raw[i].id, -1);
        cnt += 2;
    }

	for (int i = 0; i < m; i++)
		printf("%d\n", raw[ans[i]].val);
	return 0;
}
