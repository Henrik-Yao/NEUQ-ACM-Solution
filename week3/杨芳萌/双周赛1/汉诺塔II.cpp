#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int n,f[233],dp[233];
signed main(){
	for(int i=1; i<=64; i++) f[i] = 2*f[i-1] + 1;
	for(int i=1; i<=64; i++) dp[i] = f[i];
	for(int i=1; i<=64; i++) 
		for(int j=0; j<i; j++) 
			dp[i] = min(dp[i], 2*dp[j]+f[i-j]);
	while(cin>>n) cout<<dp[n]<<endl;
    return 0;
}

