#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,c;
	while(cin>>n>>c)
	{
		int we[405],va[405],dp[405][1550];
		for(int i=1;i<=n;i++)
		{
			cin>>we[i];
		}
		for(int i=1;i<=n;i++)
				{
					cin>>va[i];
      			}
      	for(int i=1;i<=n;i++)
      	{
		  	for(int j=1;j<=c;j++)
		  	{
			  	if(we[i]>j){dp[i][j]=dp[i-1][j];}
			  	else{dp[i][j]=max(dp[i-1][j],dp[i-1][j-we[i]]+va[i]);}
			}
		}
		cout<<dp[n][c]<<endl;
	}
	
	return 0;
}
