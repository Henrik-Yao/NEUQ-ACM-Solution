#include <bits/stdc++.h>
using namespace std;
int n,ans;                        //dp[i][0]��ʾ����[1,i]�в�ͬ���ֵĸ��� 
int a[1000005],dp[1000005][2];    //dp[i][1]��ʾ����[i,n]�в�ͬ���ֵĸ��� 
bool vis[1000005]; //vis[i]��ʾi�Ƿ���ֹ� 
int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n; i++)
	{
		scanf("%d",a + i);
	}
	 
	for (int i = 1;i <= n; i++)
	{
		if (!vis[a[i]]) //����δ���� 
		{
			vis[a[i]] = true;
			dp[i][0] = dp[i - 1][0] + 1;
		} else dp[i][0] = dp[i - 1][0];
	}
	
	
	memset(vis,0,sizeof(vis)); //������������¼���dp[i][1] 
	for (int i = n;i >= 1; i--) //ע��Ҫ����ѭ�� 
	{
		if (!vis[a[i]])
		{
			vis[a[i]] = true;
			dp[i][1] = dp[i + 1][1] + 1;
		} else dp[i][1] = dp[i + 1][1];
	}
	for (int i = 1;i < n; i++)
	{
		ans = max(ans,dp[i][0] + dp[i + 1][1]);  //����������[1,i]�� [i + 1,n]�Ĵ𰸺�ȡ���ֵ 
	}
	printf("%d\n",ans);
	return 0;
}
