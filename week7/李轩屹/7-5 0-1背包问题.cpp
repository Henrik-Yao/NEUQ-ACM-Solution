#include<bits/stdc++.h>
using namespace std;
int dp[401][1501];
int n,c;
int main() {
	while(cin>>n>>c){
		memset(dp,0,sizeof(dp));
		int w[401]={0},v[401]={0};
		for(int i=1;i<=n;i++) cin>>w[i];
		for(int i=1;i<=n;i++) cin>>v[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=c;j++){
				if(j>=w[i]) dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
				else dp[i][j]=dp[i-1][j];
			}
		}
		cout<<dp[n][c]<<endl;
	}      
	return 0;
}


