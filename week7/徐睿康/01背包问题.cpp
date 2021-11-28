#include<bits/stdc++.h>
using namespace std;
int n,m,w[510],v[510],dp[510][1510];
int main(){
	while(cin>>n>>m){
		for(int i=1;i<=n;i++)scanf("%d",&w[i]);
		for(int i=1;i<=n;i++)scanf("%d",&v[i]);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(j>=w[i])
					dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
				else dp[i][j]=dp[i-1][j];
			}
		}
		cout<<dp[n][m]<<endl;
	}
	return 0;
}
