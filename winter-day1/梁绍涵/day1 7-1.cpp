#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,a[1000010],sum[1000010];
signed main()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sum[1]=a[1];
	for(int i=1;i<=n;i++)
	{
		sum[i]=a[i]+sum[i-1];
//		cout<<sum[i]<<" "<<endl;
	}
	while(q--)
	{
		int flag;
		cin>>flag;
		if(flag==1)
		{
			int point,x;
			cin>>point>>x;
			for(int j=point;j<=n;j++)
			{
				sum[j]+=x;
			} 
		}
		else
		{
			int l,r;
			cin>>l>>r;
			cout<<sum[r]-sum[l-1]<<endl;
		}
	}
	return 0;
}
