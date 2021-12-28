#include<bits/stdc++.h>

using namespace std;
int n;
int ans;
int num[25];
int dp[25][25];//以num[i]结尾，长度为k的子序列数量 
map<int,int>q;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>num[i];
	for(int i=1;i<=n;i++)
	{
		dp[i][1]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int k=1;k<=i;k++)
		{
			q.clear();
			for(int j=i-1;j>=1;j--)
			{
				if(num[j]<=num[i])
				{
					if(!q[num[j]])
					{
						q[num[j]]=1;
						dp[i][k]=dp[i][k]+dp[j][k-1];
					}
				}
			}
		}
	}
	q.clear();
	for(int i=n;i>=1;i--)
	{
		if(!q[num[i]])
		{
			q[num[i]]=1;
			for(int j=2;j<=n;j++)
			{
				ans+=dp[i][j];
			}
		}
	}
	cout<<ans;
	return 0;
}
