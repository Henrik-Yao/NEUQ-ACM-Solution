#include<bits/stdc++.h>
using namespace std;
int a[2000];
int dp[2000];
int main(){
	int t;
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(0));
		int maxn=0;
		int n;
		cin>>n;
		dp[0]=1;
		for(int i=0;i<n;i++){
		cin>>a[i];
		}
		for(int i=1;i<n;i++){
			dp[i]=1;
			for(int j=0;j<i;j++){
			if(a[i]>a[j]){
				dp[i]=max(dp[j]+1,dp[i]);
			}
			}
		}
		for(int i=0;i<n;i++){
			if(dp[i]>maxn) maxn=dp[i];
		}
		cout<<maxn;
		cout<<endl;
		if(t!=0){
		cout<<endl;
	}
	}
}
