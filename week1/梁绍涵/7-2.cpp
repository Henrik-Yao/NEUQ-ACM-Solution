#include<bits/stdc++.h>
#include<map>
using namespace std;
map<int,int> a;
map<int,int> b;
int num[10010000],dp1[10000100],dp2[10000100];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
	}
	dp1[0]=0;
	dp2[n]=0;
	for(int i=1;i<=n;i++)
	{
		if(a.find(num[i])==a.end())
		{
			a[num[i]]=1;
			dp1[i]=dp1[i-1]+1;
		}
        else dp1[i]=dp1[i-1];
	}
	for(int i=n;i>=1;i--)
	{
		if(b.find(num[i])==b.end())
		{
			b[num[i]]=1;
			dp2[i]=dp2[i+1]+1;
		}
        else dp2[i]=dp2[i+1];
	}
	int ans=0;
//	for(int i=1;i<=n;i++) cout<<dp1[i]<<" ";
//	cout<<endl;
//	for(int i=1;i<=n;i++) cout<<dp2[i]<<" ";
	for(int i=1;i<n;i++)
	{
		ans=max(ans,dp1[i]+dp2[i+1]);
	}
	cout<<ans;
}

