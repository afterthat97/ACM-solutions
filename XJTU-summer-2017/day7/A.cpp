#include <iostream>
#include <stdio.h>
#include <cstring>
#include <map>
#define BufferSize 100000005
using namespace std;

typedef pair<int, int> line;
map<line, int> cnt;
char buffer[BufferSize], *head, *tail;  

char getch() {  
    if(head == tail) {  
        int l = fread(buffer, 1, BufferSize, stdin);  
        tail = (head = buffer) + l;
    }
    return *head++;  
}

#define getch getchar

int getint() {  
    int x = 0, flag = 0; char ch = getch();
    for(; !isdigit(ch); ch = getch()) 
        if (ch == '-') { flag = 1; break; }
    for(; isdigit(ch); ch = getch()) 
        x = x * 10 + ch - '0'; 
    return flag ? -x : x;
}

int main() {
	int T; T = getint();
	while (T--) {
		cnt.clear();
		int p, m, x, y, sum = 0; m = getint();
		for (int i = 0; i < m; i++) {
			x = getint(); y = getint();
			cnt[line(x, y)]++;
			cnt[line(y, x)]++;
		}
		p = getint();
		for (int i = 0; i < p; i++) {
			x = getint(); y = getint();
			sum += cnt[line(x, y)];
		}
		cout << sum << endl;
	}
	return 0;
}
