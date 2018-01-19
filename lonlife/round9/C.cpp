#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
#include <vector>
#include <functional>
#include <queue>
using namespace std;

int T, n, m, k, cost[100005], val[100005];
typedef pair<int, int> node;//first为该商品的cost值，second为其序号
bool inq[100005];

int main() {
	cin >> T;
	for (int idx = 0; idx < T; idx++) {
		priority_queue<node, vector<node>, greater<node> > q;//小根堆，维护区间中最大的m个cost值
		priority_queue<node, vector<node>, less<node> > rest;//大根堆，维护区间中剩下的商品（不在q中的商品）
		memset(inq, 0, sizeof inq);//标记某商品是否在q堆中
		scanf("%d %d %d", &n, &m, &k);
		for (int i = 0; i < n; i++) scanf("%d", &cost[i]);
		for (int i = 0; i < n; i++) scanf("%d", &val[i]);

		int happy = 0, ans = 0, l = 0, r = 0;//当前区间为[l, r - 1]
		while (r < n && l < n) {//考虑序号为r的商品
            //清除两个堆中的无效商品（即不在当前区间中的商品）
			while (!q.empty() && q.top().second < l) q.pop();
			while (!rest.empty() && rest.top().second < l) rest.pop();
			if (m > 0) {//如果还有免费的机会，直接将第r个商品纳入购买区间
				q.push(node(cost[r], r)); inq[r] = 1;
				happy += val[r];
				if (happy > ans) ans = happy;
				m--; r++;
				continue;
			}
			node now = q.top();
			//免费的机会都用完了
            if (k >= min(now.first, cost[r])) {//剩余的钱可以买下q中最便宜的商品或者r号商品
				//更新q所维护的最大的m个cost值
                if (now.first < cost[r]) {
					q.pop(); inq[now.second] = 0;
					q.push(node(cost[r], r)); inq[r] = 1;
					rest.push(now);
				} else
					rest.push(node(cost[r], r));
				k -= min(now.first, cost[r]);
				happy += val[r];
				if (happy > ans) ans = happy;
				r++;
			} else {//无论如何都无法将第r个商品纳入区间，只能丢弃区间最左边的l号商品
				if (inq[l]) {//如果l在q中，则删除后需要从rest中选出cost最大的商品来替换l
					if (rest.empty())//若rest为空，则放弃填补，免费机会+1
						m++; 
					else {
						q.push(rest.top()); inq[rest.top().second] = 1;
						k += cost[rest.top().second];
						rest.pop();
					}
				} else
					k += cost[l];
				happy -= val[l];
				l++;//l++即删除l号商品
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
