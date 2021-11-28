#include<bits/stdc++.h>
using namespace std;
int n,c;
void f();
int main(){
	while(cin>>n>>c){
		f();
	}
	return 0;
}
void f(){
	int dp[n+10][c+10];
	for(int i=0;i<=n;i++)dp[i][0]=0;
	for(int i=0;i<=c;i++)dp[0][i]=0;
	int w[n+10],v[n+10];
	w[0]=0,v[0]=0;
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1;i<=n;i++)cin>>v[i];
//	for(int i=1;i<=n;i++)cout<<w[i];
//	for(int i=1;i<=n;i++)cout<<v[i];
	for(int j=1;j<=n;j++){
		for(int k =1;k<=c;k++){
			if(w[j]>k)dp[j][k]=dp[j-1][k];
			else dp[j][k]=max(dp[j-1][k],dp[j-1][k-w[j]]+v[j]);
		}
	}
	cout<<dp[n][c]<<endl;
}
