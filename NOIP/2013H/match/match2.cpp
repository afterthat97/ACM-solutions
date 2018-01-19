//mid-quick-sort, designed for 100000 numbers.
#include <iostream>
using namespace std;
int n, a[100000][2], b[100000][2], ans, temp[100000];
int raw_a[100000], raw_b[100000];

void qsort_a(int l, int r) {
	int i = l, j = r, mid = a[(i + j) / 2][0];
	do {
		while (a[i][0] < mid) i++;
		while (a[j][0] > mid) j--;
		if (i <= j) {
			swap(a[i][0], a[j][0]);
			swap(a[i][1], a[j][1]);
			i++, j--;
		}
	} while (i <= j);
	if (l < j) qsort_a(l, j);
	if (i < r) qsort_a(i, r);
}

void qsort_b(int l, int r) {
	int i = l, j = r, mid = b[(i + j) / 2][0];
	do {
		while (b[i][0] < mid) i++;
		while (b[j][0] > mid) j--;
		if (i <= j) {
			swap(b[i][0], b[j][0]);
			swap(b[i][1], b[j][1]);
			i++, j--;
		}
	} while (i <= j);
	if (l < j) qsort_b(l, j);
	if (i < r) qsort_b(i, r);
}

void merge(int low, int mid, int high) {
	int i = low, j = mid + 1, size = 0;
	//* temp = new int[high - low + 1];
	for (; (i <= mid) && (j <= high); size++)
		if (raw_a[i] < raw_a[j])
			temp[size] = raw_a[i++];
		else {
			ans += (mid - i + 1);
			if (ans >= 99999997) ans %= 99999997;
			temp[size] = raw_a[j++];
		}
	while (i <= mid) temp[size++] = raw_a[i++];
	while (j <= high) temp[size++] = raw_a[j++];
	for (i = 0; i < size; i++)
		raw_a[low + i] = temp[i];
}

void merge_sort(int low, int high) {
	if (low >= high)
		return;
	int mid = (low + high) / 2;
	merge_sort(low, mid);
	merge_sort(mid + 1, high);
	merge(low, mid, high);
}

int main() {
	cin >> n;
	//a = new int[n];
	//b = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i][0], a[i][1] = i, raw_a[i] = a[i][0];
	for (int i = 0; i < n; i++)
		cin >> b[i][0], b[i][1] = i, raw_b[i] = b[i][0];

	qsort_a(0, n - 1);
	qsort_b(0, n - 1);

	for (int i = n - 1; i > -1; i--) 
		raw_a[a[i][1]] = b[i][1];

	merge_sort(0, n - 1);
	cout << ans;
	//system("pause");
	return 0;
}


