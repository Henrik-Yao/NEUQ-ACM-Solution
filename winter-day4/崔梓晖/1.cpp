#include <bits/stdc++.h>
using namespace std;
long long n,e,u,v,w,a[200][200],sum[500];
int main()
{
	while(cin>>n>>e)
	{
		memset(sum,0,sizeof(sum));
		memset(a,10000,sizeof(a));
		for(int i=0;i<e;i++)
		{
			cin>>u>>v>>w;
			a[u][v]=w;
			a[v][u]=w;
		}
		for(int k=0;k<n;k++)
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(a[i][j]>a[i][k]+a[k][j])
					{
						a[i][j]=a[i][k]+a[k][j];
					}
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i!=j)
				sum[i]=sum[i]+a[i][j];
			}
		}
		//for(int i=0;i<n;i++)
		//{
		//	cout<<i<<" "<<sum[i]<<endl;
		//}
		long long minn=99999999999;
		int ans;
		for(int i=0;i<n;i++)
		{
			if(minn>sum[i])
			{
				minn=sum[i];
				ans=i;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
