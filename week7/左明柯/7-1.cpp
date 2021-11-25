#include <bits/stdc++.h>
using namespace std;
const int N=2000;
int w[N],v[N]; int dp[N][N]={{0}};
int main(){
int n,c;
while(cin>>n>>c){
for(int i=1;i<=n;i++){
	cin>>w[i];
}
for(int i=1;i<=n;i++){
	cin>>v[i];
}
for(int i=1;i<=n;i++){
	for(int j=1;j<=c;j++){
		if(j<w[i]) dp[i][j]=dp[i-1][j];
		else dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
	}
}
int ans=0;
for(int i=1;i<=n;i++){
	for(int j=1;j<=c;j++){
		ans=max(ans,dp[i][j]);
	}
}
cout<<ans<<endl;}
return 0;

}
