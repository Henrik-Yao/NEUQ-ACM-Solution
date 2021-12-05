#include <bits/stdc++.h>
using namespace std;
int n,rong,answer;
const int M=401,N=1501;
int w[M],v[M];
int judge[N];
int main()
{
	while (scanf("%d",&n)!=EOF)
	{
		answer=0;
		cin>>rong;
		for (int i=1;i<=n;i++)//开始记录 
		{
			scanf("%d",w+i);
		}
		for (int i =1;i<=n;i++)//记录 
		{
			scanf("%d",v+i);
		}
		memset(judge,0x83,sizeof(judge));//清零 
		judge[0] = 0;
		for (int i=1;i<=n;i++)//开始试容量 
		{
			for (int j=rong;j>=w[i];j--)
			{
				judge[j]=max(judge[j],judge[j-w[i]]+v[i]);
			}
		}
		for (int i =1;i<=rong;i++)
		{
			answer= max(answer,judge[i]);
		}
		printf("%d\n",answer);
	}
}
