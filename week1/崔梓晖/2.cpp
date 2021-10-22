#include <bits/stdc++.h>
using namespace std;
int n,ans=-1,a[1000001],pd[100001],q[1000001],h[1000001];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(pd[a[i]]==0)
		{
		q[i]=q[i-1]+1;
		pd[a[i]]=1;
	    }
	    else q[i]=q[i-1];
	}
	memset(pd,0,sizeof(pd));
	for(int i=n;i>=1;i--)
	{
		if(pd[a[i]]==0)
		{ 
		 h[i]=h[i+1]+1;
		 pd[a[i]]=1;
	    }
		else h[i]=h[i+1];
	}
	for(int i=1;i<=n-1;i++)
	{
		ans=max(ans,q[i]+h[i+1]);
	}
	cout<<ans;
	return 0;
}
