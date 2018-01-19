#include <stdio.h>

int n, a[40005], num;

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
	scanf("%d", &num);
	for (int idx = 0; idx < num; idx++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		printf("%d\n", LIS());
	}
	return 0;
}
