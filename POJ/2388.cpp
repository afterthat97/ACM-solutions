#include <iostream>
#include <stdio.h>
#define MAXN 100005
using namespace std;

int qfind(int *begin, int *end, int k) {
    if (end - begin <= 1) return *begin;
    int key = *(begin + rand() % (end - begin - 1));
    int *i = begin, *j = end - 1;
    while (i <= j) {
        while (*i < key) i++;
        while (*j > key) j--;
        if (i <= j) swap(*(i++), *(j--));
    }
    if (k <= i - begin)
        return qfind(begin, i, k);
    else
        return qfind(i, end, k - (i - begin));
}

int n, a[MAXN];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	printf("%d\n", qfind(a, a + n, (n + 1) / 2));
	return 0;
}
