#include <bits/stdc++.h>
using namespace std;
int n,c,maxx;
int w[405],v[405];
int dp[1505];
void bb(){
	maxx = 0;
	for (int i = 1;i <= n; i++)
		cin>>w[i];
	for (int i = 1;i <= n; i++)
		cin>>v[i];
	memset(dp,0,sizeof(dp));
	dp[0]=0;
	for (int i=1;i<=n;i++)
	for (int j=c;j>=w[i];j--)
		dp[j]=max(dp[j],dp[j-w[i]]+v[i]);		
	for (int i=1;i<=c;i++)
		maxx=max(maxx,dp[i]);
	cout<<maxx<<endl;
}
int main(){
	while (cin>>n>>c){
		bb();
	}
	return 0;
}
