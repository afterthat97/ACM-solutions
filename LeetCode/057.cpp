#include "all.h"

class Solution {
public:
    vector<Interval> insert(vector<Interval>& a, Interval ins) {
        vector<Interval> ans;
		int done = 0;
		for (int i = 0; i < a.size(); i++)
			if (a[i].end < ins.start)
				ans.push_back(a[i]);
			else if (a[i].start > ins.end) {
				if (!done) {
					ans.push_back(ins);
					done = 1;
				}
				ans.push_back(a[i]);
			} else {
				ins.start = min(ins.start, a[i].start);
				ins.end = max(ins.end, a[i].end);
			}
		if (!done) ans.push_back(ins);
		return ans;
    }
};

int main() {
	int n; cin >> n;
	vector<Interval> a;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		a.push_back(Interval(x, y));
	}
	Interval ins;
	cin >> ins.start >> ins.end;
	vector<Interval> ans = Solution().insert(a, ins);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].start << ' ' << ans[i].end << endl;
	return 0;
}
