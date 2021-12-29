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
        for(int i=0;i<n;i++)
        {
            int a,b,c;
            cin>>a>>b;
            for(int i=0;i<b;i++)
            {
                cin>>c;
                dp[a][c]=1;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
            	for(int l=0;l<n;l++)
            	{
            		if(dp[i][l]+dp[l][j]<dp[i][j])
						dp[i][j]=dp[i][l]+dp[l][j];
				}
			}
        }
        for(int i=0;i<e;i++)
        {
            int a,b;
            cin>>a>>b;
            if(dp[a][b]!=1e9+7)
                cout<<dp[a][b]<<endl;
            else
                cout<<"connection impossible"<<endl;
        }
    }
}
