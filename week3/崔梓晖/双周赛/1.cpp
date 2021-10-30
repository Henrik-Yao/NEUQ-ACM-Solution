#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,a[10001],dp[10001],ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		dp[i]=max(dp[i-1]+a[i],a[i]);
		ans=max(dp[i],ans);
	}
	cout<<ans<<endl;
	return 0;
}
