#include<iostream>
#include<cstdio>
#include<string>
#define int long long
#define maxn 1000005
using namespace std;

int read()
{
	int x=1,res=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		x=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		res=res*10+(c-'0');
		c=getchar();
	}
	return res*x;
}

int ans[maxn],pd[maxn];

int rd(int deep)
{
	int l,r,val;
	val=read();
	if(val==0) return 0;
	else 
	{
		l=rd(deep+1);r=rd(deep+1);
		if(l==0&&r==0)
		{
			pd[deep]=1;
			ans[deep]+=val;
		}
	}
	return 1;
}

signed main()
{
	int an=-2e9,m;
	rd(0);
	for(int i=100;i>=1;i--)
	{
		if(pd[i]==1)
		{
//			cout<<ans[i]<<endl;
			if(an<ans[i])
			{
				an=ans[i];
				m=i;
			}
		}
	}
	cout<<m;
	return 0;
}
