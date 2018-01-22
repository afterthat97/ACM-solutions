#include "all.h"

class Solution {
public:
    double myPow(double a, int ki) {
		long long k = ki;
        double ans = 1;
		if (k < 0) {
			k = -k;
			a = 1 / a;
		}
		for (; k; k >>= 1) {
			if (k & 1) ans = ans * a;
			a = a * a;
		}
		return ans;
    }
};

int main() {
	double x; int n;
	while (cin >> x >> n)
		cout << Solution().myPow(x, n) << endl;
	return 0;
}
