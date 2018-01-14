#include <iostream>
#include <stdio.h>
using namespace std;

int n;
double w, have[1005], price[1005], p;

int main() {
	cin >> n >> w;
	for (int i = 0; i < n; i++)
		cin >> have[i];
	for (int i = 0; i < n; i++) {
		cin >> p;
		price[i] = p / have[i];
	}
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (price[i] < price[j]) {
				swap(price[i], price[j]);
				swap(have[i], have[j]);
			}
	double ans = 0;
	for (int i = 0; i < n && w > 0; i++) {
		double need = min(w, have[i]);
		w -= need;
		ans += need * price[i];
	}
	printf("%.2lf", ans);
	return 0;
}
