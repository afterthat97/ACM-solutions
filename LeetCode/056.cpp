#include "all.h"

bool cmp(const Interval& a, const Interval& b) {
	if (a.start != b.start) return a.start < b.start;
	return a.end < b.end;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& a) {
        sort(a.begin(), a.end(), cmp);
		vector<Interval> ans;
		for (int i = 0; i < a.size(); i++) {
			int st = a[i].start, ed = a[i].end;
			while (i + 1 < a.size() && a[i + 1].start <= ed && a[i + 1].start >= st) {
				ed = max(ed, a[i + 1].end);
				++i;
			}
			ans.push_back(Interval(st, ed));
		}
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
	vector<Interval> ans = Solution().merge(a);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].start << ' ' << ans[i].end << endl;
	return 0;
}
