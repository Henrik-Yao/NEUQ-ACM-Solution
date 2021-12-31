#include<bits/stdc++.h>
using namespace std;
int dp[405][1505];
int w[405],v[405];

int main()
{
	int n,c,i,j;
	while(~scanf("%d%d",&n,&c))
	{
		for(i=0;i<405;i++)
			for(j=0;j<1505;j++)
				dp[i][j]=0;
		for(i=1;i<=n;i++)
			scanf("%d",&w[i]);
		for(i=1;i<=n;i++)
			scanf("%d",&v[i]);
		int bag=c;
		int ma=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=bag;j++)
			{
				if(j<w[i])
				dp[i][j]=dp[i-1][j];
				else
				{
					dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
					ma=max(ma,dp[i][j]);
				}
				//cout<<dp[i][j]<<' ';
			}
			//cout<<endl;
		}
		cout<<ma<<endl;
	}
	return 0;
}
