#include<iostream>
#include<cmath>
#include<string.h>
#include<algorithm>
using namespace std;
int w[2000];
int v[2000];
int dp[2000];
int m, n;
int main() {
	while(cin >> n >> m){
		memset(v,0,sizeof(v));
		memset(w,0,sizeof(w));
		memset(dp,0,sizeof(dp));
	for (int i = 1; i <=n; i++) {
		cin >> w[i]; 
	}
	for (int i = 1; i <=n; i++) {
		cin >> v[i]; 
	}
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >=w[i]; j--) {
				dp[j] = max(dp[j - w[i]] + v[i], dp[j]);
		}
	}
	cout << dp[m]<<endl;
}
}
