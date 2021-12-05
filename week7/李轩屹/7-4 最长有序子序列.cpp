#include<bits/stdc++.h>
using namespace std;
int n;
int main() {
	int t;
	cin>>t;
	while(t--){
	    int a[1005]={0},dp[1005]={0},ans=0;
		cin>>n;
		dp[1]=1;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=2;i<=n;i++){
			for(int j=1;j<i;j++){
				if(a[i]>a[j]){
					dp[i]=max(dp[i],dp[j]+1);
				}
				if(j==i-1&&dp[i]==0) dp[i]++;
			}
		}
		for(int i=1;i<=n;i++){
			ans=max(ans,dp[i]);
		}
		cout<<ans<<endl;
		if(t) cout<<endl;
	}
	return 0;
}


