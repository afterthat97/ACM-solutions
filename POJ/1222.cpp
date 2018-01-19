#include <iostream>
using namespace std;

const int maxn = 30;
int a[31][32], num, n[31];

void row_echelon_form() {
	int px = 1, py = 1;
	for (int i = 1; i <= maxn; i++) {
		while (a[px][py] == 0) {
			for (int j = px + 1; j <= maxn; j++)
				if (a[j][py]) {
					for (int k = 1; k <= maxn + 1; k++)
						swap(a[px][k], a[j][k]);
					py--;
					break;
				}
			py++;
			if (py >= maxn + 1) return;
		}
		for (int j = px + 1; j <= maxn; j++)
			if (a[j][py]) {
				for (int k = 1; k <= maxn + 1; k++) {
					a[j][k] -= a[px][k];
					a[j][k] = (a[j][k] + 2) % 2;
				}
			}
		px++;
		py++;
	}
}
void row_simplest_form() {
	int px, py;
	for (int i = maxn; i > 1; i--) {
		int j;
		for (j = 1; j <= maxn + 1; j++)
			if (a[i][j] == 1) break;
		if (j - 1 == maxn + 1 && a[i][j - 1] == 0) continue;
		px = i;
		py = j;
		for (j = px - 1; j >= 1; j--)
			if (a[j][py]) {
				for (int k = 1; k <= maxn + 1; k++) {
					a[j][k] -= a[px][k];
					a[j][k] = (a[j][k] + 2) % 2;
				}
			}
	}
}

int main() {
	cin >> num;
	for (int idx = 0; idx < num; idx++) {
		for (int i = 1; i <= maxn; i++) {
			a[i][i] = 1;
			if (i - 6 > 0) a[i][i - 6] = 1;
			if (i % 6 != 1) a[i][i - 1] = 1;
			if (i % 6) a[i][i + 1] = 1;
			if (i + 6 < maxn + 1) a[i][i + 6] = 1;
		}
		for (int i = 1; i <= maxn; i++)
			cin >> a[i][maxn + 1];
		row_echelon_form();
		row_simplest_form();
		cout << "PUZZLE #" << idx + 1 << endl;
		for (int i = 1; i <= maxn; i++) {
			if (i % 6)
				cout << a[i][maxn + 1] << ' ';
			else
				cout << a[i][maxn + 1] << endl;
		}
	}
	return 0;
}
