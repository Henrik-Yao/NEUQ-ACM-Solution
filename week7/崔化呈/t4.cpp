#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,a[1010],dp[1010];
    
	cin>>t;
	while(t--)
	{
        int ans=-1;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
            dp[i]=1;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				if(a[i]>a[j])
				{
                    
					dp[i]=max(dp[i],dp[j]+1);
				}
			}
			ans=max(ans,dp[i]);
		}
        if(t>0){cout<<ans<<endl<<endl;}
        else{cout<<ans<<endl;}
	}
	return 0;
    
}
