#include <iostream>
using namespace std;

int n, a[100050];

void insert(int *t, int &size, int x) {
	if (size <= 0) {
		t[0] = x;
		size++;
		return;
	}
	int low = 0, high = size - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (x < t[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}

	if (low >= size)
		t[size++] = x;
	else
		if (t[low] < x)
			t[low + 1] = x;
		else
			t[low] = x;
}

int LIS() {
	int ans = 0;
	int *temp = new int[n];
	for (int i = 0; i < n; i++)
		insert(temp, ans, a[i]);
	delete[] temp;
	return ans;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	cout << LIS();
	return 0;
}
