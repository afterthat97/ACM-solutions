#include <iostream>
#include <stdio.h>
#define read(i) scanf("%d", &i);

using namespace std;

int dp[25][15050], c[25], w[25], n, m, weight;

void solve(){
	dp[0][7500]=1;
	for (int i=1;i<=n;i++){
		for (int j=-weight;j<=weight;j++){
			int sum=0;
			for (int k=1;k<=m;k++)
				if (j-w[i]*c[k]>=-weight && j-w[i]*c[k]<=weight)
					sum+=dp[i-1][j-w[i]*c[k]+7500];
			dp[i][j+7500]=sum;
		}
	}
}

int main(){
	read(m)read(n);
	for (int i=1;i<=m;i++) read(c[i]);
	weight=15*n*25;
	for (int i=1;i<=n;i++) read(w[i]);
	solve();
	printf("%d", dp[n][7500]);
	return 0;
}
