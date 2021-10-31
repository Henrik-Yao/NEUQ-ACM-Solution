#include<bits/stdc++.h>
using namespace std;
int n,m;
int mian[100005];//0向内    1向外 
string name[100005];
int now=1;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>mian[i];
		cin>>name[i];
	}
	for(int i=1;i<=m;i++)
	{
		int c,d;//0左  1右 
		cin>>c>>d;
		if(mian[now]==1)
		{
			if(c==0)
			{
				now+=d;
				if(now>n)now-=n;
			}
			if(c==1)
			{
				now-=d;
				if(now<1)now+=n;
			}
		}
		else if(mian[now]==0)
		{
			if(c==0)
			{
				now-=d;
				if(now<1)now+=n;
			}
			if(c==1)
			{
				now+=d;
				if(now>n)now-=n;
			}
		}
	}
	cout<<name[now];
	return 0;
}
