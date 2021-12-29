#include <bits/stdc++.h>
using namespace std;
int n,e;
int dp[101][101];
int main()
{
    while(cin>>n>>e)
    {
    	for(int i=0;i<n;i++)
    		for(int j=0;j<n;j++)
    		{
    			if(i!=j)
    			dp[i][j]=1e9+7;
    			else
    			dp[i][j]=0;
			}
        for(int i=0;i<e;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            dp[a][b]=c;
            dp[b][a]=c;
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
            	for(int l=0;l<n;l++)
            	{
            		if(dp[i][l]+dp[l][j]<dp[i][j])
						dp[i][j]=dp[i][l]+dp[l][j];
						dp[j][i]=dp[i][j];
				}
			}
        }
        int minm=1000000000,m;
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=0;j<n;j++)
            {
                sum+=dp[i][j];
            }
            if(minm>sum)
            {
                minm=sum;
                m=i;
            }
        }
        cout<<m<<endl;
    }
}
