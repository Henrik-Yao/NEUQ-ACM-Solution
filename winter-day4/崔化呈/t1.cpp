#include <bits/stdc++.h>
using namespace std;
const int M=105;
const int maxx=9999999;
int main()
{
	int mp[M][M];
	int n,e;
	while(~scanf("%d%d",&n,&e))
	{
		fill(mp[0],mp[0]+M*M,maxx);
		for(int i=0;i<e;i++)
		{
			int fr,to,v;
			scanf("%d%d%d",&fr,&to,&v);
			mp[fr][to]=v;
			mp[to][fr]=v;
		}
		for(int i=0;i<n;i++)
		{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				if(mp[i][j]>mp[i][k]+mp[k][j])
				{
					mp[i][j]=mp[i][k]+mp[k][j];
				}
			}
		}
		}
		int sum[M];
		fill(sum,sum+M,0);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i!=j){sum[i]+=mp[i][j];}
			}
		}
		int ans=maxx;
		int pos=0;
		for(int i=0;i<n;i++)
		{
			if(sum[i]<ans){ans=sum[i];pos=i;}
		}
		//cout<<ans<<endl;
		printf("%d\n",pos);
	}
	
}
