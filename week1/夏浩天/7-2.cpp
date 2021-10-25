#include <iostream>
#include<string.h>
using namespace std;
int n,ans;                        //dp[i][0]表示区间[1,i]中不同数字的个数 
int a[1000002],dp[1000002][2];    //dp[i][1]表示区间[n - i + 1,n]中不同数字的个数 
bool vis[1000002]; //i是否出现过 
int main()
{
	cin>>n;
	for (int i = 1;i <= n; i++)
	{
		cin>>a[i];
	}
	 
	for (int i = 1;i <= n; i++)
	{
		if (!vis[a[i]]) //该数未出现 
		{
			vis[a[i]] = true;
			dp[i][0] = dp[i - 1][0] + 1;
		} else dp[i][0] = dp[i - 1][0];
	}
	
	
	memset(vis,0,sizeof(vis)); //清空数组再重新计算dp[i][1] 
	for (int i = n;i >= 1; i--) //注意要倒叙循环 
	{
		if (!vis[a[i]])
		{
			vis[a[i]] = true;
			dp[i][1] = dp[i + 1][1] + 1;
		} else dp[i][1] = dp[i + 1][1];
	}
	for (int i = 1;i < n; i++)
	{
		ans = max(ans,dp[i][0] + dp[i + 1][1]);  //对两段区间[1,i]和 [i + 1,n]的答案和取最大值 
	}
	cout<<ans;
	return 0;
}
