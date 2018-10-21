#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <map>
#include <string>
#include <queue>
using namespace std;

struct node {
    string nums;
    int pos, steps;
};

map<string, int> ans;

void bfs() {
    queue<node> q;
    q.push({ "01234567", 0, 0 });
    while (!q.empty()) {
        node cnt = q.front(); q.pop();
        if (ans.find(cnt.nums) != ans.end()) continue;
        ans[cnt.nums] = cnt.steps;
        int pos = cnt.pos;
        if (pos - 1 >= 0 && pos != 4) {
            swap(cnt.nums[pos], cnt.nums[pos - 1]);
            q.push({ cnt.nums, pos - 1, cnt.steps + 1 });
            swap(cnt.nums[pos], cnt.nums[pos - 1]);
        }
        if (pos + 1 <= 7 && pos != 3) {
            swap(cnt.nums[pos], cnt.nums[pos + 1]);
            q.push({ cnt.nums, pos + 1, cnt.steps + 1 });
            swap(cnt.nums[pos], cnt.nums[pos + 1]);
        }
        if (pos - 4 >= 0) {
            swap(cnt.nums[pos], cnt.nums[pos - 4]);
            q.push({ cnt.nums, pos - 4, cnt.steps + 1 });
            swap(cnt.nums[pos], cnt.nums[pos - 4]);
        }
        if (pos + 4 <= 7) {
            swap(cnt.nums[pos], cnt.nums[pos + 4]);
            q.push({ cnt.nums, pos + 4, cnt.steps + 1 });
            swap(cnt.nums[pos], cnt.nums[pos + 4]);
        }
    }
}

int main() {
    bfs();
    string line;
	while (getline(cin, line)) {
		line.erase(remove(line.begin(), line.end(), ' '), line.end());
		cout << ans[line] << endl;
	}
    return 0;
}
