#include<bits/stdc++.h> 
using namespace std;
int arr[1010],dp[1010];

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,i,j;
		memset(arr,0,sizeof(arr));
		for(i=0;i<1010;i++)
			dp[i]=1;
		cin>>n;
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<i;j++)
			{
				if(arr[j]<arr[i])
				dp[i]=max(dp[j]+1,dp[i]);
			}
		}
		int ma=0;
		for(i=0;i<n;i++)
			ma=max(ma,dp[i]);
		cout<<ma<<endl;
	}
	return 0;
}
