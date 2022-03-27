#include<bits/stdc++.h>
using namespace std;
int a[1000005]={};
int c1[1000005]={};
int c2[1000005]={};
bool b1[1000005]={};
bool b2[1000005]={};
int main()
{
	int n,s1=0,s2=0,maxx;
	cin>>n;
	for(int i=1;i<=n;i++)//输入
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)//求前部分权值
	{
		if(b1[a[i]]==0)
		{
			b1[a[i]]=1;
			s1++;
		}
		c1[i]=s1;
	}
	for(int i=n;i>=1;i--)//求后部分权值
	{
		if(b2[a[i]]==0)
		{
			b2[a[i]]=1;
			s2++;
		}
		c2[i]=s2;
		maxx=max(maxx,c2[i]+c1[i-1]);
	}
	cout<<maxx;
    return 0;
}
//枚举断点//用数组存权值数