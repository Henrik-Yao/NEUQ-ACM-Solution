#include<iostream>
using namespace std;
int a[100000],dp[100000];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,i,j,length=1;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			dp[i]=1;
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<i;j++)
			{
				if(a[i]>a[j])
				{
					if(dp[j]+1>dp[i])
					{
						dp[i]=dp[j]+1;
					}
				}
			}
			if(dp[i]>length)
			{
				length=dp[i];
			}
		}
		if(t>0)
		{
			cout<<length<<endl<<endl;
		}
		else
		{
			cout<<length;
		}
	}
	return 0;
} 
