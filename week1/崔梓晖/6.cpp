#include <bits/stdc++.h>
using namespace std;
int n,t,a[10001],w[10001],ans[10001],maxx=-99999999;
int main()
{
	cin>>n>>t;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>w[i];
		if(w[i]<=t)
		{
			ans[i]=a[i];
		}
		if(w[i]>t)
		{
			ans[i]=a[i]-(w[i]-t);
		}
		maxx=max(maxx,ans[i]);
	}
	cout<<maxx;
	return 0;
}

