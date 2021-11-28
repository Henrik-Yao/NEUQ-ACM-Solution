#include<bits/stdc++.h>
using namespace std;
int t,n,dp[10010],a[10010],ans=-1;
int main(){
	cin>>t;
	while(t--){
		scanf("%d",&n);
		ans=1;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			dp[i]=1;
		}
		for(int i=2;i<=n;i++){
			for(int j=1;j<i;j++){
				if(a[i]>a[j]){
					dp[i]=max(dp[i],dp[j]+1);
				}
			}
			ans=max(ans,dp[i]);
		}
		//for(int i=1;i<=n;i++)cout<<dp[i]<<' ';
		if(t!=0)
		printf("%d\n\n",ans);
		else
		printf("%d",ans);
	}
	return 0;
}
