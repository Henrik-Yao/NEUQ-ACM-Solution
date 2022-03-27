#include<bits/stdc++.h>
using namespace std;
int main(){
	int dp[100000],t,a[100000],n,maxx;
	cin>>t;
	while(t--){
		maxx=0;
		cin>>n;
		for(int i=0;i<n;i++)
		cin>>a[i],dp[i]=1;
	    for(int i=0;i<n;i++){
		    for(int j=i;j>=0;j--)
				if(a[i]>a[j]){dp[i]=max(dp[i],dp[j]+1);break;}
			if(maxx<dp[i]) maxx=dp[i];
	    }
	    cout<<maxx<<endl;
	    if(t)cout<<endl;
	}
	return 0;
}
