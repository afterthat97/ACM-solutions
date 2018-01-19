#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#define ll long long
#define INF 0x3f3f3f3f
#define maxn 300000
#define BufferSize (1 << 16)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

ll addv[maxn], sumv[maxn], minv[maxn], maxv[maxn];
int n, m, _n;
char buffer[BufferSize], *head, *tail;  

char getch() {  
    if(head == tail) {  
        int l = fread(buffer, 1, BufferSize, stdin);  
        tail = (head = buffer) + l;
    }
    return *head++;  
}  

int getint() {  
    int x = 0, flag = 0; char ch = getch();
    for(; !isdigit(ch); ch = getch()) 
		if (ch == '-') { flag = 1; break; }
	for(; isdigit(ch); ch = getch()) 
		x = x * 10 + ch - '0'; 
    return flag ? -x : x;
}  

void init() {
	memset(addv, 0, sizeof addv);
	memset(sumv, 0, sizeof sumv);
	memset(minv, INF, sizeof minv);
	memset(maxv, -1, sizeof maxv);
	_n = 1; while (_n < n) _n <<= 1;
	for (int i = _n; i < _n + n; i++)
		minv[i] = maxv[i] = sumv[i] = addv[i] = getint();
	for (int p = _n >> 1; p; p >>= 1)
		for (int i = p; i < (p << 1); i++) {
			int lt = i << 1, rt = i << 1|1;
			sumv[i] = sumv[lt] + sumv[rt];
			maxv[i] = max(maxv[lt], maxv[rt]);
			minv[i] = min(minv[lt], minv[rt]);
		}
}

void maintain(int k, int l, int r) {
	int lt = k << 1, rt = k << 1|1;
	sumv[k] = minv[k] = maxv[k] = 0;
	if (r > l) {
		sumv[k] = sumv[lt] + sumv[rt];
		minv[k] = min(minv[lt], minv[rt]);
		maxv[k] = max(maxv[lt], maxv[rt]);
	}
	minv[k] += addv[k];
	maxv[k] += addv[k];
	sumv[k] += addv[k] * (r - l + 1);
}

void add(int k, int l, int r, int a, int b, int v) {
	int lt = k << 1, rt = k << 1|1;
	if (a <= l && r <= b)
		addv[k] += v;
	else {
		int mid = (l + r) >> 1;
		if (a <= mid) add(lt, l, mid, a, b, v); 
		if (mid < b) add(rt, mid + 1, r, a, b, v); 
	}
	maintain(k, l, r);
}

ll query(int k, int l, int r, int a, int b, ll add) {
	if (r < a || l > b) return 0;//or INF, -INF
	if (a <= l && r <= b)
		return sumv[k] + add * (r - l + 1);
	int mid = (r + l) >> 1, lt = k << 1, rt = k << 1|1;
	return query(lt, l, mid, a, b, add + addv[k]) 
		+ query(rt, mid + 1, r, a, b, add + addv[k]);
}

void sqr(int k, int l, int r, int a, int b, ll add) {
	int lt = k << 1, rt = k << 1|1;
	if (a <= l && r <= b && maxv[k] + add == 1) return;
	if (a <= l && r <= b
	&& (maxv[k] == minv[k]
		|| (maxv[k] == minv[k] + 1 
			&& (ll)sqrt(maxv[k] + add) == (ll)sqrt(minv[k] + add) + 1)))
				addv[k] -= maxv[k]  + add - (ll)(sqrt(maxv[k] + add));
	else {
		int mid = (l + r) >> 1;
		if (a <= mid) sqr(lt, l, mid, a, b, add + addv[k]);
		if (mid < b) sqr(rt, mid + 1, r, a, b, add + addv[k]);
	}
	maintain(k, l, r);
}

int main() {
	int T = getint();
	while (T--) {
		n = getint(); m = getint();
		init(); int cho, l, r;
		for (int i = 0; i < m; i++) {
			cho = getint(); l = getint(); r = getint();
			if (cho == 1) {
				int x = getint();
				add(1, 1, _n, l, r, x);
			} else if (cho == 2) {
				sqr(1, 1, _n, l, r, 0);
			} else
				printf("%lld\n", query(1, 1, _n, l, r, 0));
		}
	}
	return 0;
}
