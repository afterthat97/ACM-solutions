#include <iostream>
#include <stdio.h>
#include <algorithm>

const int BufferSize = 1 << 16;  
char buffer[BufferSize], *head, *tail;  

inline char getch() {  
    if(head == tail) {  
        int l = fread(buffer, 1, BufferSize, stdin);  
        tail = (head = buffer) + l;
    }
    return *head++;  
}  
inline int getint() {  
    int x = 0, flag = 0; char ch = getch();
    for(; !isdigit(ch); ch = getch()) 
		if (ch == '-') { flag = 1; break; }
	for(; isdigit(ch); ch = getch()) 
		x = x * 10 + ch - '0'; 
    return flag ? -x : x;
}  

#define maxm 1000005
#define maxn 200005
int a[maxn], b[maxm], n, ans;

int main() {
	n = getint();
	for (int i = 0; i < n; i++) a[i] = getint();
	std::sort(a, a + n); a[n] = maxm - 1; 
	for (int i = 0; i < n; i++)
		for (int j = a[i] + 1; j <= a[i + 1]; j++)
			b[j] = a[i];
	for (int i = 0; i < n; i++)
		for (int j = a[i] << 1; j < maxm; j += a[i])
			if (b[j] % a[i] > ans) ans = b[j] % a[i];
	printf("%d\n", ans);
	return 0;
}
